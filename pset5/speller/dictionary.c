// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dictionary.h"

// Represents number of children for each node in a trie
#define N 27

// Represents a node in a trie
typedef struct node
{
    bool is_word;
    struct node *children[N];
}
node;

// Represents a trie
node *root;

int words = 0;

int charToInt(const char c)
{
    if (c == '\'')
    {
        return N-1;
    }
    else
    {
        return tolower(c) - 'a';
    }
}

void unloading(node* curr)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (curr->children[i] != NULL)
        {
            unloading(curr->children[i]);
        }
    }
    free(curr);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize trie
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        return false;
    }
    root->is_word = false;
    for (int i = 0; i < N; i++)
    {
        root->children[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into trie
    while (fscanf(file, "%s", word) != EOF)
    {
        // TODO
        int i, j;
        node *curr = root;
        node *next;

        for (i = 0; word[i] != '\0'; i++) {
            int x = charToInt(word[i]);
            //printf("%i\n", x);

            if (curr->children[x] == NULL) {
                next = malloc(sizeof(node));
                next->is_word = false;
                for (j = 0; j < N; j++) {
                    next->children[j] = NULL;
                }
            }
            else {
                curr->children[x] = next;
            }
        }
        next->is_word = true;
        words++;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return words;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int i;
    node *curr = root;
    for (i = 0; word[i] != '\0'; i++)
    {
        int x = charToInt(word[i]);
        curr = curr->children[x];

        if (curr == NULL)
        {
            return false;
        }
    }

    if (curr->is_word == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node* curr = root;
    unloading(curr);
    return true;
}
