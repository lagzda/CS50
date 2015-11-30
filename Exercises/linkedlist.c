#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//A singly linked list implementation (ordered as elements are inserted)

//Define a struct called node which holds the value and points to the next node
typedef struct node{
    int value;
    struct node * next;
} node;

//Prototypes
void traverse(node * head);
void populate(node * head);
void clean(node * head);
void insert(int value, node * head);

int main(){
    //Inititate the head of the list which will be the primary point of reference.
    node * head;
    //Allocate some memory for head.
    head = malloc(sizeof(node)); 
    populate(head);
    insert(1,head);
    traverse(head);
    clean(head);
    return 0;
}
//Insert 3,5,7,9 in to the linked list
void populate(node * head){
    printf("The default list is 3->5->7->9\n");
    //Set a "crawler" to point to head
    node * ptr = head;
    //Iteratively insert each value
    for (int i = 3; i < 10; i += 2){
        ptr->value = i;
        //This is needed to ground the last node (setting it to not point to anything)
        if (i + 1 == 10){
            ptr->next = NULL;
        }
        //Allocate memory for each new node
        else {
            node * new = malloc(sizeof(node));
            //Set the current node's next reference to the new node
            ptr->next = new;
            //Make the "crawler" point to the new node
            ptr = ptr->next;
        }
    }
}
void traverse(node * head){
    if (head == NULL){
        printf("The list is empty\n");
    }
    else{
    //Initiate the "crawler" pointing to the first node (head)
    node * ptr = head;
    printf("The list is: \n");
    //If the "crawler" becomes NULL it means that it is end of the list
    while (ptr != NULL){
        //Print the current value
        printf("%i ", ptr->value);
        //Set the "crawler" to the next node
        ptr = ptr->next;   
    }
    printf("\n");
    }
}
void insert(int value, node * head){
    //Initiate "crawler" to point to head
    node * ptr = head;
    //If the value we want to add is the smallest value
    if (value < ptr->value){
        //Initiate a new node and set it's values exactly like head's.
        node * new = malloc(sizeof(node));
        new->value = ptr->value;
        new->next = ptr->next;
        //Now change the current head's value to the new and point it to the past head.
        ptr->value = value;
        ptr->next = new; 
    }
    else{
    //Not yet implemented    
    }    
}
void clean(node * head){
    if (head == NULL){
        printf("Cleaned up! \n");
    }
    node * ptr = head;
    while (ptr != NULL){
        node * prev = ptr;
        ptr = ptr->next;
        free(prev);
    }
    printf("Cleaned up! \n");
}
