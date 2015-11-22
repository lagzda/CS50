#include <stdio.h>

int main(int argc, char * argv[]){
    if (argc != 2){
        printf("<Usage: ./filetotext [filename]>\n");
        return 1;
    }
    FILE * file = fopen(argv[1], "r");
    if (file == NULL){
        printf("No such file: %s\n", argv[1]);
        return 1;
    }
    for(int c = fgetc(file); c != EOF; c = fgetc(file)){
        putchar(c);
    }
    fclose(file);
    printf("\n");
    return 0;
}
