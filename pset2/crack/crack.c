#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    const char salt[3] = {argv[1][0], argv[1][1]};

    char guessPassword[6];

    for (int i = 48; i <= 122; i++)
    {
        guessPassword[0] = (char)i;
        if (strcmp(crypt(guessPassword, salt), argv[1]) == 0)
        {
            printf("%s\n", guessPassword);
            return 0;
        }
    }

    for (int i = 48; i <= 122; i++)
    {
        for (int j = 48; j <= 122; j++)
        {
            guessPassword[0] = (char)i;
            guessPassword[1] = (char)j;
            if (strcmp(crypt(guessPassword, salt), argv[1]) == 0)
            {
                printf("%s\n", guessPassword);
                return 0;
            }
        }
    }

    for (int i = 48; i <= 122; i++)
    {
        for (int j = 48; j <= 122; j++)
        {
            for (int k = 48; k <= 122; k++)
            {
                guessPassword[0] = (char)i;
                guessPassword[1] = (char)j;
                guessPassword[2] = (char)k;
                if (strcmp(crypt(guessPassword, salt), argv[1]) == 0)
                {
                    printf("%s\n", guessPassword);
                    return 0;
                }
            }
        }
    }

    for (int i = 48; i <= 122; i++)
    {
        for (int j = 48; j <= 122; j++)
        {
            for (int k = 48; k <= 122; k++)
            {
                for (int l = 48; l <= 122; l++)
                {
                    guessPassword[0] = (char)i;
                    guessPassword[1] = (char)j;
                    guessPassword[2] = (char)k;
                    guessPassword[3] = (char)l;
                    if (strcmp(crypt(guessPassword, salt), argv[1]) == 0)
                    {
                        printf("%s\n", guessPassword);
                        return 0;
                    }
                }
            }
        }
    }

    for (int i = 48; i <= 122; i++)
    {
        for (int j = 48; j <= 122; j++)
        {
            for (int k = 48; k <= 122; k++)
            {
                for (int l = 48; l <= 122; l++)
                {
                    for (int m = 48; m <= 122; m++)
                    {
                        guessPassword[0] = (char)i;
                        guessPassword[1] = (char)j;
                        guessPassword[2] = (char)k;
                        guessPassword[3] = (char)l;
                        guessPassword[4] = (char)m;
                        if (strcmp(crypt(guessPassword, salt), argv[1]) == 0)
                        {
                            printf("%s\n", guessPassword);
                            return 0;
                        }
                    }
                }
            }
        }
    }
}