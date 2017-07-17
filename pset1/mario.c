#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int height;
    int spaces = 2;
    int hashes = 1;

    do{
        printf("height: ");
        height = get_int();
    }while(height < 0 || height >= 24);
    
    for(int i = 0; i < height; i++)
    {
        for (int j = spaces; j <= height ; j++)
        {
          printf(" ");
        }
        spaces += 1;
        for (int j = 0; j <= hashes ; j++)
        {
          printf("#");
        }
        hashes += 1;
      printf("\n");
    }
}