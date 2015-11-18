#include <stdio.h>

int * selection(int list[],int size){
    for (int i = 0; i < size; i++){
        int min = i;
        for (int j = i+1;j<size;j++){
            if(list[min]>list[j]){
                min = j;
            }  
        }
        if (min!=i){
            int temp = list[i];
            list[i] = list[min];
            list[min] = temp;
        }
    }
    return list;
}

int main(int argc, char * argv[]){
    int list[] = {1,5,4,2,7};
    int size = 5;
    int * sorted = selection(list,size);
    for (int i = 0; i < size; i++){
        printf("%d", sorted[i]);
    }
    return 0;
}
