// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // 1. Hash word to obtain value
    int index = hash(word);
    // 2. Acces to the corresponding index in hash table
    node *list = table[index];
    // 3. Traves linked list and look for the word
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        int compare = strcasecmp(ptr->word, word);
        if (compare == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // int hashvalue = toupper(word[0]) - 'A';
    int hashvalue = 0;
    int f_letter = toupper(word[0]) - 'A';
    int s_letter = toupper(word[1]) - 'A';
    // If word has mora than one letter
    if (strlen(word) > 1)
    {
        hashvalue = (('Z' - 'A') * f_letter) + (f_letter + s_letter);
    }
    // If the word has 1-char word
    else
    {
        hashvalue = ('A' - 'B') * f_letter + f_letter;
    }
    return hashvalue;
}
int counter = 0; // Variable to count words in dictionaru
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // 1. OPEN DICTIONAY
    // Open file in read mode
    FILE *r_dictionary = fopen(dictionary, "r");
    // Check if the file was opened correctly
    if (r_dictionary == NULL)
    {
        fprintf(stderr, "%s could not opend!\n", dictionary);
        return 1;
    }
    // 2. READ STRINGS FROM DICTIONARY 1 AT THE TIME
    // Create an array to read strings from the dictonary
    char buffer[LENGTH + 1];
    while (fscanf(r_dictionary, "%s", buffer) != EOF)
    {
        // Count number of words in dictionary
        counter++;
        // 3. CREATE A NEW NODE FOR EACH WORD
        // Allocate memory
        node *n = malloc(sizeof(node));
        // Check memory allocation
        if (n == NULL)
        {
            fprintf(stderr, "It has not been possible to allocate memory\n");
            return 2;
        }
        // copy words from dictionary
        strcpy(n->word, buffer);
        n->next = NULL;
        // 4. HASH THE WORD AND OBTAIN THE H. VALUE
        unsigned int index = hash(n->word);
        // 5. INSERT THE NODE IN THE RIGHT LOCATION
        // Insert node in right index at hash table
        // If index is empty
        if (table[index] == NULL)
        {
            table[index] = n;
        }
        // If index has already elements
        else
        {
            n->next = table[index]->next;
            table[index]->next = n;
        }
    }
    // close file after used
    fclose(r_dictionary);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *ptr = NULL;
    node *tmp = NULL;
    // Free indexes in the table
    for (int i = 0; i < N; i++)
    {
        // Free linked list starting at index i
        ptr = table[i];
        while (ptr != NULL)
        {
            tmp = ptr;
            ptr = ptr->next;
            free(tmp);
        }
    }
    return true;
}
