#include <stdio.h>

void swap(int * x, int * y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(void){
    int x,y;
    printf("First number please: ");
    scanf("%i", &x);
    printf("Second number please: ");
    scanf("%i", &y);
    printf("X is now %i and Y is now %i \n", x,y);
    printf("Swapping \n");
    swap(&x,&y);
    printf("X is now %i and Y is now %i \n", x,y);
}
