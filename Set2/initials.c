#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[]){
    printf("Enter your full name: ");
    string s = GetString();
    char previous;
    for (int i = 0, n = strlen(s); i<n; i++){
        if (!isalpha(previous) && isalpha(s[i])){
            if (islower(s[i])){
                printf("%c",s[i]-32);
            } else {
                printf("%c",s[i]);
            }
        }
        previous = s[i];   
    }
    printf("\n");
    return 0;
}
