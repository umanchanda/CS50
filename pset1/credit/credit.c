#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

int numDigits(long long);
bool isValid(long long);

int main(void)
{
    long long number;
    char n[11];

    do
    {
        number = get_long_long("Number: ");
    }
    while (number < 0);

    sprintf(n, "%lld", number);


    if (n[0] == '4' && (numDigits(number) == 13 || numDigits(number) == 16))
    {
        printf("VISA\n");
    }

    else if (n[0] == '3' && (n[1] == '4' && n[1] == '7') && numDigits(number) == 15)
    {
        printf("AMEX\n");
    }

    else if (n[0] ==  '5' && (n[1] == '1' || n[1] == '2' || n[1] ==  '3' || n[1] == '4' || n[1] == '5') && numDigits(number) == 16)
    {
        printf("MASTERCARD\n");
    }

    else
    {
        printf("INVALID\n");
    }

}

int numDigits(long long n)
{
    int digits  = 0;

    while (n != 0)
    {
        n /= 10;
        digits++;
    }
    return digits;
}

bool isValid(long long n)
{
    char s[11];
    sprintf(s, "%lld", n);

    int i, sum = 0;
    int addsum = 0, x2prod = 0;
    for (i = strlen(s); i >= 0; i -= 2)
    {
        addsum += (int)s[i];
    }

    for (i = strlen(s) - 1; i > 0; i -= 2)
    {
        x2prod += (((int)s[i]) * 2);
    }

    sum += (addsum + x2prod);

    if (sum % 10 == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}