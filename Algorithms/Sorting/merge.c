#include <stdio.h>

//This is the actual merging function of the two arrays. This is not called to start sort
void merge(int values[], int min, int mid, int max){
    int i,j;
    //Define the sizes of the two halves of the array
    int lsize = mid - min + 1;
    int rsize = max - mid;
    //Initialise the two halves
    int left[lsize], right[rsize];
    //Populate them
    for (i=0;i<lsize;i++){
        left[i] = values[min+i];
    }
    for (j=0;j<rsize;j++){
        right[j] = values[mid+j+1];
    }
    i=0;
    j=0;
    int k = min;
    //Sort the elements while merging the arrays
    while (i<lsize && j<rsize){
        if (left[i]<=right[j]){
            values[k] = left[i];
            i++;
        } else {
            values[k] = right[j];
            j++;
        }
        k++; 
    }
    //If some elements still exist in either half add them to merged list
    while (i < lsize){
        values[k] = left[i];
        i++;
        k++;
    }
    while (j < rsize){
        values[k] = right[j];
        j++;
        k++;
    }   
}
//This is the partitioning function where the array is divided until atomic  
void mergeSort(int values[], int min, int max){
    if (min<max){
        int mid = (min+max)/2;
        mergeSort(values, min, mid);
        mergeSort(values, mid+1, max);
        //Then starting from the smalles array merge and sort it by calling the above defined merge
        merge(values, min, mid, max);
    }
}
//Test
int main(int argc, char * argv[]){
    int list[] = {1,8,7,9,2,3,5};
    //One way to calculate size of the array
    int size = sizeof(list)/sizeof(*list);
    mergeSort(list, 0, size-1);
    //Check if the sort worked by printing the sorted list
    for (int i = 0; i<size; i++){
        printf("%d", list[i]);
    }
    printf("\n");
    return 0;
}
