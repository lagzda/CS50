#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

//This function takes a full name and tranforms it into initials.

int main(int argc, char* argv[]){
    printf("Enter your full name: ");
    string s = GetString();
    char previous;
    for (int i = 0, n = strlen(s); i<n; i++){
        //If previous letter was not an alphabetic character and the current is it is an initial.
        if (!isalpha(previous) && isalpha(s[i])){
            //Convert to upper
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
