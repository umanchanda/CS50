#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        exit(1);
    }

    int k = atoi(argv[1]);

    if (k < 0)
    {
        printf("Usage: ./caesar k\n");
        exit(1);
    }

    string s = get_string("plaintext: ");

    int i, n;

    char cipher[strlen(s) + 1];
    for (i = 0, n = strlen(s); i < n; i++)
    {
        if (islower(s[i]))
        {
            cipher[i] = (char)((((int) s[i] + k - 97) % 26) + 97);
        }

        else if (isupper(s[i]))
        {
            cipher[i] = (char)((((int) s[i] + k - 65) % 26) + 65);
        }

        else
        {
            cipher[i] = s[i];
        }
    }
    printf("ciphertext: %s\n", cipher);
}