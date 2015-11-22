#include <stdio.h>

int main(void){
    FILE * file = fopen("helloworld","w");
    if (file != NULL){
        fprintf(file, "Hello, world");
        fclose(file);
    }
    return 0;
}
