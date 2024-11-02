#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void encrypt(string plain, int k);

int main(int argc, string argv[])
{
    //Checks that key is prompted by commandline args
    if (argc != 2)
    {
        printf("Error. Usage: ./caesar + key");
        return 1;
    }
    //Checks that key is a decimal digit
    for (int i = 0, s = strlen(argv[1]); i < s; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Error. Key must be a valid number.");
            return 1;
        }

    }

    //Convert key to integer
    int key = atoi(argv[1]);

    //Ask for plaintext
    string plaintext = get_string("plaintext: ");

    //Print Ciphertext
    printf("ciphertext: ");
    encrypt(plaintext, key);
}

void encrypt(string plain, int k)
{
    for (int j = 0, sp = strlen(plain); j < sp; j++)
    {
        if (isalpha(plain[j])) //Checks if alphabetical
        {
            if (isupper(plain[j])) //Checks if uppercase character
            {
                printf("%c", (plain[j] - 65 + k) % 26 + 65);
            }
            if (islower(plain[j])) //Checks if lowercase character
            {
                printf("%c", (plain[j] - 97 + k) % 26 + 97);
            }
        }
        else
        {
            printf("%c", plain[j]); //Print non-alphabetical character without ciphering.
        }
    }
    printf("\n");
}