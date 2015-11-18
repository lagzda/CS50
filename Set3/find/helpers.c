/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    for (int i = 0; i < n; i++){
        if(values[i]==value){
            return true;
        } 
    }
    return false;
}

void selection (int values[], int n){
     for (int i = 0; i<n; i++){
        int min = i;
        for (int j = i+1; j<n; j++){
            if (values[min] > values[j]){
                min = j;
            }
        }
        if (min!=i){
            int temp = values[i];
            values[i] = values[min];
            values[min] = temp;
        }
     }
}
void insertion(int values[], int n){
    for (int i = 1; i < n; i++){
        int element = values[i];
        int j = i;
        while(j>0 && element<values[j-1]){
            values[j] = values[j-1];
            j = j - 1;
        }
        values[j] = element;
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    insertion(values, n);
    return;
}
