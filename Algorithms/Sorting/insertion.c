#include <stdio.h>

int * insertion(int size, int list[]){
    for (int i = 1; i < size; i++){
        int element = list[i];
        int j = i;
        while (j > 0 && list[j-1]>element){
            list[j] = list[j-1];
            j -= 1;
        }
        list[j] = element;
    }
    return list;
}

int main(int argc, char * argv[]){
    int list[] = {5,4,2,6,1};
    int size = 5;
    int * sort = insertion(size, list);
    for (int i = 0;i<5;i++){
        printf("%d",sort[i]);
    }
    printf("\n");
    return 0;
}
