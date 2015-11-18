#include <stdio.h>
#include <cs50.h>

void swap(int * x, int * y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(int argc, char * argv[]){
    printf("Enter 1st insteger: ");
    int x = GetInt();
    printf("Enter 2nd insteger: ");
    int y = GetInt();
    printf("Swapping %d and %d \n", x, y);
    swap(&x,&y);
    printf("Done! x = %d and y = %d \n", x, y);
}
