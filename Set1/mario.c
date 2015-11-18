#include <stdio.h>
#include <cs50.h>
#include <string.h>
int main(void){
    printf("Please enter the height (0:23): ");
    int height = GetInt();
    for (int i=0; i < height;i++){
        int indent = height - i;
        printf("%*s",indent,"#");
        for (int j = 0;j<i;j++){
            printf("#");
        }
        printf("  ");
        for (int j = 0;j<i+1;j++){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
