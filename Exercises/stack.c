#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

//Struct class
typedef struct{
    int list[MAXSIZE];
    int top;
}Stack;

//Prototypes
void push(int value, Stack * s);
int pop(Stack * s);

int main(void){
    Stack * s = malloc(sizeof(Stack));
    s->top = -1;
    push(3, s);
    push(4, s);
    printf("%i\n", pop(s));
    printf("%i\n", pop(s));
    printf("%i\n", pop(s));
    //Free the allocated memory for stack
    free(s); 
}

//A function that pushes a value onto a stack
void push(int value, Stack * s){
    //Check if top of stack has not reached the maximum
    if (s->top == MAXSIZE - 1){
        printf("Stack is full\n");
    }
    else {
        //Increment the top first and add the value at top's index
        s->top = s->top + 1;
        s->list[s->top] = value;
        
    }   
}
int pop(Stack * s){
    //Check if there is anything to remove from list
    if (s->top < 0){
        printf("The stack is empty\n");
        return s->top;
    }
    else{
        //Save top temporarily so we can decrement it whilst returning the previous value
        int temp = s->top;
        s->top = s->top -1;
        return s->list[temp];    
    }
}
