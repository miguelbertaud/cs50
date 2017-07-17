#include<stdio.h>
#include<cs50.h>
#include <math.h>

int main(void)
{
    float change;
    int coinsUsed = 0;
    
    do{
        
        printf("O hai! How much change is owed?\n");
        change = get_float();
        
    }while(change < 0);
    
    float cents = round(change * 100);

    
    while(cents >= 25)
    {
        cents -= 25;
        coinsUsed += 1;
    }
    while(cents >= 10)
    {
        cents -= 10;
        coinsUsed += 1;
    }
    while(cents >= 5)
    {
        cents -= 5;
        coinsUsed += 1;
    }
    while(cents >= 1)
    {
        cents -= 1;
        coinsUsed += 1;
    }
    
    printf("%i\n", coinsUsed);
}