#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

char modify(char c){
 if (isupper(c)){
    return c - 65;
 } else {
    return c - 97;
 }
}
char transform(char c, char key){
    if (isupper(c)){
        return (modify(c)+modify(key))%26+65;
    } else {
        return (modify(c)+modify(key))%26+97;
    }
}

int main(int argc, char* argv[]){
    if (argc == 2){ 
        string keyword = argv[1];
        string s = GetString();
        int count = 0;
        for (int i = 0, n = strlen(s); i<n; i++){
            if (isalpha(s[i])){
                int keynum = count%strlen(keyword);
                printf("%c", transform(s[i],keyword[keynum]));
                count += 1;
            } else {
                printf("%c",s[i]);
            }
        }
            printf("\n");
            return 0;
    } else {
        printf("Bad!\n");
        return 1;
    }
}
