// program that takes in an integer value between 0 and 23 and outputs a full pyramid with a space in the middle

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);


    int i, space, hash;

    for (i = 0; i < height; i++)
    {
        for (space = 0; space < height - i - 1; space++)
        {
            printf("%s", " ");
        }

        for (hash = 0; hash <= i; hash++)
        {
            printf("%s", "#");
        }

        printf("%s", "  ");

        for (hash = 0; hash <= i; hash++)
        {
            printf("%s", "#");
        }

        printf("\n");
    }
}