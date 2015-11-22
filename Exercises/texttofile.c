#include <stdio.h>
int count(char * pos){
    int count = 0;
    for (char * position = pos; position != '\0'; position++){
        count++;
    }
    printf("%i",count);
    return count;
}
int main(int argc, char * argv[]){
    if (argc < 2){
        printf("<Usage: ./texttofile [filename] [string]>\n");
        return 1;
    }
    FILE * file = fopen(argv[1], "w");
    if (file == NULL){
        printf("Could not create %s",argv[1]);
        return 1;
    } 
    for (int i = 2; i < argc; i++){
        fprintf(file, "%s ", argv[i]);
    }
    fclose(file);
    
    return 0;
}
