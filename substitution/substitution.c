#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool check_key(string key);
void encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    //Checks that key is prompted by commandline args
    if (argc != 2)
    {
        printf("Error. Usage: ./substitution + key\n");
        return 1;
    }
    if (!check_key(argv[1]))
    {
        printf("Key must contain 26 unique characters.");
        return 1;
    }
    //Ask for plaintext
    string plaintext = get_string("plaintext: ");

    //Encrypt plaintext with key values
    encrypt(plaintext, argv[1]);
}
//checks that key is 26 alphabetical unique characters.
bool check_key(string key)
{
    int length;
    length = strlen(key);

    //key is not 26 characters long
    if (length != 26)
    {
        return false;
    }
    //convert key to uppercase
    for (int y = 0; y < length; y++)
    {
        key[y] = toupper(key[y]);
    }
    //key is not alphabetical
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        //key is not unique
        for (int j = i + 1; j < length; j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }
    return true;
}

void encrypt(string plaintext, string key)
{
    int index, length;
    length = strlen(plaintext);
    char ciphertext[length + 1];
    for (int i = 0; i < length; i++)
    {
        if (isupper(plaintext[i]))
        {
            index = plaintext[i] -= 65;
            ciphertext[i] = key[index];
            if (islower(ciphertext[i]))
            {
                ciphertext[i] += 32;
            }
        }
        else if (islower(plaintext[i]))
        {
            index = plaintext[i] -= 97;
            ciphertext[i] = key[index];
            if (isupper(ciphertext[i]))
            {
                ciphertext[i] += 32;
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[length] = '\0';
    printf("ciphertext: %s\n", ciphertext);
}