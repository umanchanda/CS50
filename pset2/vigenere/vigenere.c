#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        exit(1);
    }
    else
    {
        int a;
        for (a = 0; a < strlen(argv[1]); a++)
        {
            if (!isalpha(argv[1][a]))
            {
                exit(1);
            }
        }
    }

    int keylength = strlen(argv[1]);
    string key = argv[1];

    string plaintext = get_string("plaintext: ");
    char cipher[strlen(plaintext)];

    int i, j;

    for (i = 0, j = 0; i < strlen(plaintext); i++)
    {
        int k = (int)((tolower(key[j % keylength]) - 97) % 26);

        if (islower(plaintext[i]))
        {
            cipher[i] = (char)((((int) plaintext[i] + k - 97) % 26) + 97);
            j++;
        }
        else if (isupper(plaintext[i]))
        {
            cipher[i] = (char)((((int) plaintext[i] + k - 65) % 26) + 65);
            j++;
        }
        else
        {
            cipher[i] = plaintext[i];
        }
    }

    printf("ciphertext: %s\n", cipher);
}