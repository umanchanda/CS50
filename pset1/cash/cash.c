// program that asks the user for change and returns the minimum number of coins needed

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;

    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);

    int numcoins = 0;
    int c = (int) round(change * 100);

    while (c >= 25)
    {
        numcoins++;
        c -= 25;
    }

    while (c >= 10)
    {
        numcoins++;
        c -= 10;
    }

    while (c >= 5)
    {
        numcoins++;
        c -= 5;
    }

    while (c >= 1)
    {
        numcoins++;
        c -= 1;
    }

    printf("%d\n", numcoins);
}