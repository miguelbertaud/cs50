#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("missing command-line arguments\n");
        return 1;
    }
    
    string s = argv[1];
    int key = atoi(s);
    
    printf("plaintext: ");
    string plainText = get_string();
    printf("ciphertext: ");
    for(int i = 0, n = strlen(plainText); i < n; i++ )
    {
        if(isalpha(plainText[i]))
        {
            if(isupper(plainText[i]))
            {
                printf("%c",(((plainText[i] - 65) + key) % 26) + 65);
            }
            else
            {
                printf("%c",(((plainText[i] - 97) + key) % 26) + 97);
            }
        }
        else
        {
            printf("%c", plainText[i]);    
        }
    }
    printf("\n");
    return 0;
}

