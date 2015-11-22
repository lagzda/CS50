#include <stdio.h>

typedef struct{
    char * name;
    int size;
}Pizza;

int main(int argc, char * argv[]){
    Pizza pizza = {"Salami", 30}; 
    printf("%i cm big %s pizza\n", pizza.size, pizza.name);
    return 0;
}
