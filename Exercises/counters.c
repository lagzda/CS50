#include <stdio.h>
// Integer only counter
void intcount(int * first){
    int count = 0;
    while (*first != '\0'){
        count++;
        first++;
    }
    printf("%i ints \n", count);
}
// Char only counter
void charcount(char * first){
    int count = 0;
    while (*first != '\0'){
        count++;
        first++;
    }
    printf("%i chars \n", count);
}

int main(void){
    int intarray[] = {1,2,3,4,5,6,7,8};
    char * chararray = "asdfghjkl";
    intcount(intarray);
    charcount(chararray);
}
