//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 500
#define WIDTH 410

// height and width of paddle in pixels
#define PHEIGHT 10
#define PWIDTH 100

//height and width of bricks in pixels
#define BHEIGHT 10
#define BWIDTH 30

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);

// colors for bricks
char * colors[] = {"BLUE","RED","ORANGE","YELLOW","GREEN"};

// added lives for visual representation
void initLives(GWindow window, GOval * livesRep ,int count);

void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

// GODMODE
bool godmode = false;

// paddle shrinking coefficient
double shrink = 1;

// instantiate laser shot
GLine shootLaser(GWindow window, GRect paddle);

// initiate fired laser shot to false 
bool fired = false;
GLine shot = NULL;

int main(int argc, char * argv[])
{
    // check if user inputed godmode
    if (argc == 2 && strcmp(argv[1], "GOD")==0){
        godmode = true;   
    }
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);
    
    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;
    
    // instantiate lives representations
    GOval livesRep[lives];
    initLives(window, livesRep, lives); 

    // number of points initially
    int points = 0;
    
    // velocity
    double velocityX = drand48()*2.0;
    double velocityY = 2.0;
    
    // keep playing until game over
    bool paused = true;
    while (lives > 0 && bricks > 0)
    {   
        // if game not paused move the ball around 
        if (!paused){
            move(ball,velocityX,velocityY);
            pause(2);
        }
        // if laser shot is fired move the shot toward bricks
        if (fired){
            move(shot,0,-1);
        }
        // if godmode is enabled make paddle follow ball
        if (godmode) {
            paused = false;
            double x = getX(ball) - getWidth(paddle)/2;
            setLocation(paddle, x, getY(paddle));
        }
        // collisions logic
        // detect lasershot and brick collision 
        if (fired){
            GObject hit = detectCollision(window,shot);
            if (hit != NULL){
                if (strcmp(getType(hit),"GRect")==0){
                    points+=(100-(getY(hit)))/10;
                    removeGWindow(window,hit);
                    removeGWindow(window,shot);
                    freeGObject(hit);
                    freeGObject(shot);
                    fired = false;
                    bricks-=1;
                    updateScoreboard(window,label,points);       
                }
            }
        }
        // detect ball and paddle collision
        GObject object = detectCollision(window,ball);
        if (object!=NULL){
            if (object == paddle){
                if (getX(ball)> getX(object)+(getWidth(object)/2)){
                    if (velocityX<0){
                        velocityX = -velocityX;
                    }
                } else {
                    if (velocityX>0){
                        velocityX = -velocityX;
                    }
                }
                velocityY = -velocityY;
            }
            if(strcmp(getType(object),"GRect")==0 && object!=paddle && object!=shot){
                shrink -= 0.01;
                // Apply shrink to paddle
                setSize(paddle, PWIDTH*shrink, PHEIGHT);
                velocityY = -velocityY;
                //Scoring 1:3:5:7:9 from lowest to highest
                points+=(100-(getY(object)))/10;
                removeGWindow(window,object);
                freeGObject(object);
                bricks-=1;
                updateScoreboard(window,label,points);   
            }
        }
        
        if (!godmode){
        GEvent event = getNextEvent(MOUSE_EVENT);
        if (event != NULL){
            // Move paddle
            if (getEventType(event) == MOUSE_MOVED){
                double x = getX(event) - getWidth(paddle)/2;
                setLocation(paddle, x, getY(paddle));
            }
            // Shoot laser
            if (getEventType(event) == MOUSE_CLICKED && !paused && !fired){
                shot = shootLaser(window, paddle);
            }
            // Start or resume game from paused
            if (getEventType(event) == MOUSE_CLICKED){
                paused = false;
            }
            
        }
        }
        
        if (getX(ball)+getWidth(ball)>=getWidth(window)){
            velocityX = -velocityX;
        }
        if (getX(ball)<=0){
            velocityX = -velocityX;
        }
        if (getY(ball)+getHeight(ball)>=getHeight(window)){
            lives -= 1;
            removeGWindow(window, livesRep[lives]);
            removeGWindow(window,ball);
            ball = initBall(window);
            if (lives == 0){
                setLabel(label,"Game Over");
                double x = (getWidth(window) - getWidth(label)) / 2;
                double y = (getHeight(window) - getHeight(label)) / 2;
                setLocation(label, x, y);
                pause(1000);
            } 
            else {
                velocityX = drand48()*2.0;
                paused = true;
            }   
        }
            if (getY(ball)<=0){
                velocityY = -velocityY;
            }
        
    }
    // If all the bricks are cleared then the player wins
    if(bricks == 0){
        setLabel(label,"You won!");
        double x = (getWidth(window) - getWidth(label)) / 2;
        double y = (getHeight(window) - getHeight(label)) / 2;
        setLocation(label, x, y);
        pause(1000);   
    }
    // wait for click before exiting
    waitForClick();

    // game over
    
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            GRect brick = newGRect(j*BWIDTH+(10*(j+1)), i*BHEIGHT+(10*(i+1)), BWIDTH, BHEIGHT);
            setFilled(brick,true);
            setColor(brick,colors[i%5]);
            add(window,brick);
        }
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{   
    double circled = RADIUS*2;
    GOval circle = newGOval((WIDTH-circled)/2,HEIGHT/2,circled,circled);
    add(window,circle);
    return circle;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    GRect paddle = newGRect((WIDTH-PWIDTH)/2,4*HEIGHT/5,PWIDTH,PHEIGHT);
    setFilled(paddle, true);
    setColor(paddle,"BLACK");
    add(window,paddle);
    return paddle;
}
/**
 * Instantiates lives representation in left bottom corner.
 */
void initLives(GWindow window, GOval * livesRep ,int count){
    for (int i = 0; i < count; i++){
        GOval life = newGOval(20*i,HEIGHT-20,20,20);
        setFilled(life,true);
        setColor(life,"BLACK");
        add(window,life);
        livesRep[i] = life; 
    }    
}
/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("0");
    setFont (label, "SansSerif-36");
    double x = (getWidth(window)-getWidth(label))/2;
    double y = (getHeight(window)-getHeight(label))/2;
    setLocation(label,x,y);
    add(window,label);
    return label;
}
/**
 * Instantiates laser
 */
GRect shootLaser(GWindow window, GRect paddle){
    int lw = 2;
    int lh = 10;
    double posx = getX(paddle) + (getWidth(paddle)) / 2.0 + lw / 2.0;
    double posy = getY(paddle) - lh - 10;
    GLine shot = newGLine(posx, posy, posx, posy-10); 
    setFilled(shot, true);
    setColor(shot,"GREEN");
    add(window,shot);
    fired = true;
    return shot; 
}
 
/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
