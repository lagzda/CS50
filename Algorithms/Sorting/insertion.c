#include <stdio.h>

void insertion(int values[], int n){
    //Mentally split array into two parts : Sorted | Unsorted.
    //Leave the first element in the sorted part. 
    for (int i = 1; i < n; i++){
        int element = values[i];
        int j = i;
        //Go backwards through the imagined sorted list to find the sorted place for the next element from the unsorted part.
        while(j>0 && element<values[j-1]){
            values[j] = values[j-1];
            j = j - 1;
        }
        values[j] = element;
    }
}

int main(int argc, char * argv[]){
    int list[] = {1,8,7,9,2,3,5};
    //One way to calculate size of the array
    int size = sizeof(list)/sizeof(*list);
    insertion(list,size);
    //Check if the sort worked by printing the sorted list
    for (int i = 0; i<size; i++){
        printf("%d", list[i]);
    }
    printf("\n");
    return 0;
}
