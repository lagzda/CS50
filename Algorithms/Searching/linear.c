#include <stdio.h>
#include <stdlib.h>

int linear(int item, int array[], int size){
    for (int i = 0;i<size;i++){
        if(item == array[i]){
            printf("Found it!\n");
            return 0;
        }
    }
    return 1;  
}
int main(int argc, char * argv[]){
     int list[] = {1,2,3,4,5,6,7,8,9,0};
     int item = atoi(argv[1]);
     linear(item,list,sizeof(list)/sizeof(*list));
     return 0;
}
