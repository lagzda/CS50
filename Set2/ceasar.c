#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//A function that rotates entered string by specified number of positions

char transform(char c, int key){
    if(isupper(c)){
        return ((c - 65 + key)%26)+65; 
    } else {
        return ((c - 97 + key)%26)+97;
    }
}
int main(int argc, char* argv[]){
    //Check if input is provided
    if (argc == 2){
        int key = atoi(argv[1]);
        string s = GetString();
        //Iterate and rotate each character by calling transform
        for (int i = 0, n = strlen(s);i<n;i++){
            if (isalpha(s[i])){
                char c = transform(s[i], key);
                printf("%c", c);  
            } else {
                printf("%c", s[i]);
            }
        }
        printf("\n");
        return 0;
    }else{
        printf("Bad!\n");
        return 1;
    }
}
