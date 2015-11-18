#include <stdio.h>
#include <cs50.h>
#include <string.h>
int main(void)
{
    string card = "378282246310005";
    int total = 0;
    for (int n = strlen(card)-2; n >= 0; n -= 2)
    {   
        int prod = (card[n]-48)*2;
        if (prod >= 10){
            prod = prod/10 + prod%10;  
        }
        total += prod;
    }
    
    for (int n = strlen(card)-1; n >= 0; n -= 2){
        total += (card[n]-48);
    }
    
    if (total%10 == 0){
        printf("Valid!\n");
    }
    return 0;
}
