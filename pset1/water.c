#include<stdio.h>
#include<cs50.h>

int main(void)
{
    printf("minutes: ");
    int min = get_int();
    
    int bottles = min * 12;
    
    printf("bottles: %i\n", bottles);
}