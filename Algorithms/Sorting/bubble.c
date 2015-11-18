#include <stdio.h>
#include <stdbool.h>
//Swap function that takes the address as a paramater and changes the value in the address
void swap(int * x, int * y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble(int values[], int n){
    //The first loop actually tells how many times to do the next for loop
    for (int i = 0; i < n; i++){
        //Initialise sorted bool to true to see exactly when the list is sorted and be able to quit.
        bool sorted = true;
        //Compare two elements and swap them if the latter is smaller   
        for (int j = 0; j < n-1; j++){
            if (values[j] > values[j+1]){
                swap(&values[j], &values[j+1]);
                //Since we swapped elements the list in this iteration was not sorted
                sorted = false;
            }
        }
        //When in an iteration there are no swaps it means that the array is sorted and we break the loop
        if (sorted){
            break;
        }
    }
}
int main(int argc, char * argv[]){
    int list[] = {1,8,7,9,2,3,5};
    //One way to calculate size of the array
    int size = sizeof(list)/sizeof(*list);
    bubble(list,size);
    //Check if the sort worked by printing the sorted list
    for (int i = 0; i<size; i++){
        printf("%d", list[i]);
    }
    printf("\n");
    return 0;
}
