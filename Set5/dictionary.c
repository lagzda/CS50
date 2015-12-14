/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "dictionary.h"
//Define the hashsize of every alpabetical letter times 10 slots for up to string length of 10
#define HASHSIZE 26*10

// Node struct for the linked list implementation
typedef struct node{
    char word[LENGTH+1];
    struct node * next;
}node;

//Hash table for loading the words (an array of linked lists)
node * hashtable[HASHSIZE];

//Hash function
int hash(char * first){
    //Initialise length of the word, index of the hashtable where the value will go and letter position (0-26)
    int len = strlen(first);
    int index;
    int letterpos = *first - 'a';
    //Map each word in the hashtable depending on the length of the string and first character (a goes first)
    if(len < 10){
        index = letterpos*len;
    }
    //If string is longer than 10 characters just put it in the last bucket
    else{
        index = letterpos*10;  
    }
    return index; 
}

//A function to add a node to hashtable
void add_node(node * new_node, node * hashtable[HASHSIZE], int index){
    //Set new_node to point to the previous head
    new_node->next = hashtable[index];
    //Set head to the new_node
    hashtable[index] = new_node;
}

//Keep track of the size of the hashtable
int table_size = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    //Initialise a holder for converted word to lowercase (thus achieving case insensitivity)
    char normalised[strlen(word)];
    //Convert each letter to lowercase
    for (int i = 0, length = strlen(word); i < length; i++){    
        normalised[i] = tolower(word[i]);
    }
    //Put a terminator at the end of normalised word
    normalised[strlen(word)]= '\0';
    //Get the hash index (bucket) for the word
    int index = hash(&normalised[0]);
    //Initiate a pointer at the head of the chosen bucket
    node * ptr = hashtable[index];
    //Iterate over items in the bucket
    while (ptr != NULL){
        //Compare the passed word to each word in the bucket
        if (strcmp(normalised, ptr->word) == 0){
            return true;
        }
        //If not a match, iterate
        ptr = ptr->next;
    }
    //If a match can't be found return false
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    //Initiate a buffer to hold the word, a character placeholder and i as index for the buffer
    char buffer[LENGTH+1];
    char c;
    int i = 0;
    //Open dictionary file
    FILE * dict = fopen(dictionary,"r");
    //Check for NULL
    if (dict == NULL){
        return false;
    }
    //Iterate through the dictionary file char by char until end of file is reached
    while((c = fgetc(dict)) != EOF){
        //If character is not the terminator of a word ('\n') add to buffer and increment index
        if(c != '\n'){
            buffer[i] = c;
            i++; 
        }
        //End of word is reached
        else{
            //terminate the buffer word
            buffer[i] = '\0';
            //Create a new node
            node * new_node = malloc(sizeof(node));
            //Check for NULL
            if (new_node == NULL){
                return false;
            }
            //Set new node to point to NULL 
            new_node->next = NULL;
            //Copy the buffer to the new node's word holder
            strcpy(new_node->word, buffer);
            //Get the hash for new node
            int index = hash(&buffer[0]);
            //Add the node to hashtable at given index
            add_node(new_node, hashtable, index);
            //Increment table size and set i to 0 to prepare for a new word
            table_size++;
            i = 0;
        }
    }
    //Close the dictionary file
    fclose(dict);
    return true;  
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return table_size;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    //For each bucket in hashtable
    for (int i = 0; i < HASHSIZE; i++){
        //Initiate a pointer to every bucket's head
        node * ptr = hashtable[i];
        //Iterate and free every element in a bucket
        while(ptr != NULL){
            node * temp = ptr->next;
            free(ptr);
            ptr = temp;
        }
    }
    return true;
}
