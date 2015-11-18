#include <stdio.h>
#include <stdlib.h>
int binary(int item,int list[],int min,int max){
    if (min>max){
        return -1;
    } 
    else {
        int midpoint = (min+max)/2;
        if(item > list[midpoint]){
            binary(item,list,midpoint+1,max);
        }
        else if (item < list[midpoint]){
            binary(item,list,min,midpoint-1);
        }
        else {
            printf("Found it!\n");
            return list[midpoint];
        }
    }
    return 0;
}

int main(int argc, char * argv[]){
    if (argc == 2){
        int item = atoi(argv[1]);
        int list[] = {1,2,3,4,5,6,7,8,9};
        binary(item,list,0,sizeof(list)/sizeof(*list));
        return 0;
    } else {
        printf("Dumass!");
        return 1;
    }    
}
