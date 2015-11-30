// A tetris game (UNFINISHED)
// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>
// Standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//Height and width of game window
#define HEIGHT 400
#define WIDTH 400

//Prototypes
void play(GWindow window);
bool isCollided(GWindow window, GRect brick);
void moveBrick(GRect brick);
int main(void){
    //Instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);
    play(window);
    closeGWindow(window); 
    return 0;
}
void play(GWindow window){
    while(true){
        bool collision = false;
        GRect brick = newGRect(0,0,40,40);
        add(window, brick);
        collision = isCollided(window, brick);
        while(getY(brick) < HEIGHT - 40 && !collision){
            move(brick, 0, 1);
            moveBrick(brick);
            collision = isCollided(window, brick);
            pause(20);
        }
        move(brick, 0, 1);
    }
}

void moveBrick (GRect brick){
    GEvent event = getNextEvent(KEY_EVENT);
    if (event != NULL){
        char ch = getKeyChar(event);
        if (ch == 'd'){
            move(brick, 40, 0);
        }
        if (ch == 'a'){
            move(brick, -40, 0);
        }
    }   
}
bool isCollided(GWindow window, GRect brick){
    //Get brick's location
    double x = getX(brick);
    double y = getY(brick);
    //Object that will collide against
    GObject object;
    //Check if bottom of brick collides against top of the unknown object
    object = getGObjectAt(window, x, y+41);
    
    if (object != NULL){
        if (object != brick){
            return true;
        }
    }
    return false;  
}
