#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

float getLetters(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        
    }
}

float getSentences(string text)
{
    return 0.0;
}

int main()
{
    string text = get_string("Text: ");
    int grade = round(0.0588 * getLetters(text) - 0.296 * getSentences(text) - 15.8);
    printf("Grade %d\n", grade);
}