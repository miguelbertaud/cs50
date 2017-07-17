#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //Get key in commandline argument.  Prompt until key is given.
    string key = argv[1];

    if (argc != 2)
    {
        printf("Invalid command. Please specify key.\n");
        return 1;
    }
    //Make sure only alphabetical chars are used in key.
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Invalid command. Please specify key.\n");
            return 1;
        }
    }
    int indexOfKey = 0;
    printf("plaintext: ");
    string plainText = get_string();
    printf("ciphertext: ");
    for(int i = 0, n = strlen(plainText); i < n; i++ )
    {
        if(isalpha(plainText[i]))
        {
            if(isupper(plainText[i]))
            {
                printf("%c",(((plainText[i] - 65) + (tolower(key[indexOfKey % strlen(key)]) - 97)) % 26) + 65);
                indexOfKey++;
            }
            else
            {
                printf("%c",(((plainText[i] - 97) + (tolower(key[indexOfKey % strlen(key)]) - 97)) % 26) + 97);
                indexOfKey++;
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