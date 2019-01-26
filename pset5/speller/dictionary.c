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
        return tolower(c) - '0' - 97;
    }
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
        int i;
        node *next;

        for (i = 0; i < LENGTH+1; i++) {
            int x = charToInt(word[i]);

            if (root->children[i] == NULL) {
                next = malloc(sizeof(node));
                next = next->children[x];
            }
            else {
                root = root->children[x];
            }

            if (word[i] == '\0') {
                next->is_word = true;
                words++;
            }
        }
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return words;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int i, length;
    for (i = 0, length = strlen(word); i < length; i++)
    {
        int x = charToInt(word[i]);
        root = root->children[x];

        if (!root)
        {
            return false;
        }
    }

    return root->is_word;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < LENGTH+1; i++)
    {
        free(root);
        if (root->children[i] != NULL)
        {
            return false;
        }
    }
    return true;
}
