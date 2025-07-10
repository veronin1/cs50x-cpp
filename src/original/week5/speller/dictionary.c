// Implements a dictionary's functionality
#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Choose number of buckets in hash table (chosen pal)
const unsigned int N = 2600;

// Hash table
node *table[N];

// total words
int num_words = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_value = hash(word);
    node *cursor = table[hash_value];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int total = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        char current_char = word[i];

        if (isupper(current_char))
        {
            total += word[i] - 'A';
        }
        else if (islower(current_char))
        {
            total += word[i] - 'a';
        }
    }

    total %= N;

    return total;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *src = fopen(dictionary, "r");
    if (src == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    while (fscanf(src, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, word);
        int index = hash(word);
        n->next = table[index];
        table[index] = n;
        num_words++;
    }
    fclose(src);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return num_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];

        while (ptr != NULL)
        {
            node *next = ptr->next;
            free(ptr);
            ptr = next;
        }
    }

    return true;
}
