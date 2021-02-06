#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[]) 
{
  if (argc != 2)
  {
    printf("Usage: ./substitution key");
    return 1;
  }

  string key = argv[1];

  if (strlen(key) != 26)
  {
    printf("Key must contain 26 characters.");
    return 1;
  }

  string plaintext = get_string("plaintext: ");

  int i, j;
  char ciphertext[strlen(plaintext)];
  
  for (i = 0; i < strlen(plaintext); i++)
  {
    if (isupper(plaintext[i]))
    {
      ciphertext[i] = key[(int)(plaintext[i]) % 65];
    }

    else if(islower(plaintext[i]))
    {
      ciphertext[i] = key[(int)(plaintext[i]) % 97];
    }

    else
    {
      ciphertext[i] = plaintext[i];
    }
  }

  printf("ciphertext: %s\n", ciphertext);

  return 0;
}