#include <stdio.h>
#include <stdbool.h>
int * bubble(int list[], int size){
    int temp = 0;
    for (int i = 0; i < size - 1; i++){
        bool sorted = true;
        for(int j = 0; j < size - i - 1; j++){
            if(list[j] > list[j+1]){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
                sorted = false;
                temp = 0;
            }
        }
        if(sorted){
            printf("It's sorted!\n");
            return list;
        }
    }
    return list;  
}
int main(int argc, char * argv[]){
    int list[] = {1,8,7,9,2,3,5};
    int size = sizeof(list)/sizeof(*list);
    int * sort = bubble(list,size);
    for (int k = 0;k<size;k++){
        printf("%d", sort[k]);
    }
    printf("\n");
    return 0;
}
