#include <stdio.h>
#define _XOPEN_SOURCE
#include <unistd.h>
#include <crypt.h>
#include <math.h>
#include <string.h>

void generate(int pos, char word[8], char * asci, char * salt, char * pass){
    if(pos>7){
        return;
    }
    for (int i=0;i<95;i++){
        word[pos] = asci[i];
        word[pos+1] = '\0';
        //check if wrd is password
        if (strcmp(crypt(word,salt),pass) == 0){
            printf("%s = %s", word,crypt(word,salt));
            printf(" = %s\n", pass);
            printf("Found it!");
        }
        generate(pos+1,word,asci, salt, pass);
            
    }
}
int main(int argc, char * argv[]){
    if (argc == 2){
        char * asci =  " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}";
        char word[8];
        generate(0,word, asci, "50", argv[1]);
        return 0;
    } else {
        return 1;
    }
}
