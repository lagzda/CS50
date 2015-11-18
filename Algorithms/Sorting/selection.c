#include <stdio.h>

//Swap function that takes the address as a paramater and changes the value in the address
void swap(int * x, int * y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection (int values[], int n){
    //Start with each element as the assumed minimal value of the list
    for (int i = 0; i<n; i++){
        int min = i;
        //Compare the assumed minimal value against others until a smaller value is found
        for (int j = i+1; j<n; j++){
            //Assume the new minimal value and continue the iteration
            if (values[min] > values[j]){
                min = j;
            }
        }
        //If the first assumption of each iteration is not as it was swap it for the real minimal value found
        if (min!=i){
            swap(&values[i],&values[min]);
        }
     }
}

int main(int argc, char * argv[]){
    int list[] = {1,8,7,9,2,3,5};
    //One way to calculate size of the array
    int size = sizeof(list)/sizeof(*list);
    selection(list,size);
    //Check if the sort worked by printing the sorted list
    for (int i = 0; i<size; i++){
        printf("%d", list[i]);
    }
    printf("\n");
    return 0;
}
