//My implementation of trie data structure

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// default dictionary
#define DICTIONARY "/home/cs50/pset5/dictionaries/large"

#define LENGTH 45

//The struct holds a bool that tells if it is the end of a word and a children array of letters
typedef struct trie{
    bool end;
    struct trie * children[27];
}trie;

//Prototypes
void load(trie * tr, FILE * dict);
void add_word(trie * tr, char * word);
bool check(trie * tr, char * word);


int main(void){
    trie * tr = malloc(sizeof(trie));
    tr -> end = false;
    FILE * dict = fopen(DICTIONARY, "r");
    load(tr, dict);
    fclose(dict);
    char string[LENGTH];
    while(strcmp(string, "q") != 0){
        printf("Enter a word to check or 'q' to quit: ");
        scanf("%s", string);
        bool ok = check(tr, string);
        if (ok){
            printf("The word '%s' is in the dictionary\n", string);
        }
        else{
            printf("The word '%s' is not in the dictionary\n", string);
        }
    }
    printf("Bye\n");
    return 0;
}

void load(trie * tr, FILE * dict){
    int index = 0;
    char word[LENGTH + 1];
    for (char c = fgetc(dict); c != EOF; c = fgetc(dict)){
        if (c != '\n'){
            word[index] = c;
            index++;
        }
        else{
            word[index] = '\0';
            add_word(tr, word);
            index = 0;
        }
    }
}

void add_word(trie * tr, char * word){
    char * wptr = word;
    trie * tptr = tr;
    int index = 0;
    while (*wptr != '\0'){
        if (*wptr == '\''){
            index = 26;
        }
        else{
            index = tolower(*wptr) - 'a';
        }
        if (!tptr -> children[index]){
            trie * new_tr = malloc(sizeof(trie));
            new_tr -> end = false;
            tptr -> children[index] = new_tr;
        }
        wptr++;
        tptr = tptr->children[index];
    }
    tptr->end = true;
}
bool check(trie * tr, char * word){
    char * wptr = word;
    trie * tptr = tr;
    int index = 0;
    while (*wptr != '\0'){
        if (*wptr == '\''){
            index = 26;
        }
        else{
            index = tolower(*wptr) - 'a';
        }
        if (!tptr -> children[index]){
            return false;
        }
        wptr++;
        tptr = tptr->children[index];
    }
    if (!tptr->end){
        return false;
    }
    return true;
}
