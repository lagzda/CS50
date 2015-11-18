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

//The first are searching algorithms! For comments see Algorithms folder.

//Recursive Binary Search
bool binary(int value, int values[], int min, int max){
    if(min>max){
        return false;
    }
    int midpoint = (min+max)/2;
    if(values[midpoint] > value){
        return binary(value,values,min,midpoint-1);
    }
    else if (values[midpoint] < value) {
        return binary(value,values,midpoint+1,max);
    } 
    else {
        return true;
    }
}

//Simple linear search
bool linear(int value, int values[], int size){
    for (int i = 0; i < size; i++){
        if (values[i] == value){
            return true;
        }
    }
    return false;
}
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{   
    //You can uncomment either linear or binary search to work
    //return linear(value, values, n);
    return binary(value, values, 0, n);
}

//Swap function for selection and bubble sort algorithms
void swap(int * x, int * y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//Sorting algorithms! Comments for these are in the Algorithms folder as well

//Selection Sort
void selection (int values[], int n){
     for (int i = 0; i<n; i++){
        int min = i;
        for (int j = i+1; j<n; j++){
            if (values[min] > values[j]){
                min = j;
            }
        }
        if (min!=i){
            swap(&values[i],&values[min]);
        }
     }
}

//Insertion sort
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

//Bubble Sort

void bubble(int values[], int n){
    for (int i = 0; i < n; i++){
        bool sorted = true;
        for (int j = 0; j < n-1; j++){
            if (values[j] > values[j+1]){
                swap(&values[j], &values[j+1]);
                sorted = false;
            }
        }
        if (sorted){
            break;
        }
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    //Uncomment either of the sorting algorithms to work
    //selection(values, n);
    //insertion(values, n);
    //bubble(values, n);
    return;
}
