#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cs50.h>

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
void insert(node * head);

int main(void){
    //Inititate the head of the list which will be the primary point of reference.
    node * head;
    //Allocate some memory for head.
    head = malloc(sizeof(node));
    //Check for null
    if (head == NULL){
        printf("Something went wrong\n");
        return 1;
    }
    head->next=NULL;
    //A simple number selection interface
    int selection = 0;
    while(selection != 4){
        printf("1. Populate list with default values\n");
        printf("2. Insert a value in the list\n");
        printf("3. Traverse the list\n");
        printf("4. Quit\n");
        printf("Selection: ");
        selection = GetInt();
        switch (selection){
            case 1:
                populate(head);
                break;
            case 2:
                insert(head);
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                break;    
            default:
                printf("Try again");         
        }
    }
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
            //Check for null
            if (new == NULL){
                printf("Something went wrong\n");
                break;
            }
            //It is best practice to initiate the node pointing to NULL
            new->next = NULL;
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
void insert(node * head){
    printf("Please enter a value to insert: ");
    int value = GetInt();
    //Initiate "crawler" to point to head
    node * ptr = head;
    //If the value we want to add is the smallest value
    if (value < ptr->value){
        //Initiate a new node and set it's values exactly like head's.
        node * new = malloc(sizeof(node));
        //Check for null
        if (new != NULL){
            new->value = ptr->value;
            //It is best practice to initiate the node pointing to NULL
            new->next = NULL;
            new->next = ptr->next;
            //Now change the current head's value to the new and point it to the past head.
            ptr->value = value;
            ptr->next = new;
        }
        else{
            printf("Something went wrong");
        } 
    }
    //If the node needs to be inserted somewhere in the middle or at the end of list
    else{
        //The while loop will insert the node in the middle if required
        //If that does not succeed then after the while loop we insert the node as last
        bool inserted = false;
        while(ptr->next != NULL){
            //The insertion happens between the current and the next node
            if (value < ptr->next->value && value >= ptr->value){
                //Initiate a new node and set it's values.
                node * new = malloc(sizeof(node));
                //Check for NULL 
                if ()
                new->value = value;
                //New node needs to point where the current node pointed
                new->next = ptr->next;
                //And the current node needs to point to the new node
                ptr->next = new;
                //The bool is so the program doesn't try to append another node in the end of list
                inserted = true;
                break; 
            }
            //Go to next node
            ptr = ptr->next;
        }
        //If insertion in middle did not succeed, lets insert the node in the end
        if (!inserted){
            //Create new node
            node * new = malloc(sizeof(node));
            new->value = value;
            //Ground the node
            new->next = NULL;
            //And set the current node point to the new one
            ptr->next = new;
        }    
    }    
}
//A function to free up allocated memory from heap
void clean(node * head){
    if (head == NULL){
        printf("Cleaned up! \n"); //Kind of
    }
    //Set "crawler" to point to the head of the list 
    node * ptr = head;
    while (ptr != NULL){
        //Store the current node to know where to go next after freeing it
        node * prev = ptr;
        ptr = ptr->next;
        free(prev);
    }
    printf("Cleaned up! \n");
}
