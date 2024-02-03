#include "cs50.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
// functions
int count_letters(string txt);
int count_words(string txt);
int count_sentences(string txt);
int main(void)
{
    // promt the user for some text
    string text = get_string("Text: ");
    // count letter, words and sentences
    // count lettes
    int n_letters = count_letters(text);
    // printf("letters: %d\n",n_letters);
    // count words
    int n_words = count_words(text);
    // printf("words: %d\n", n_words);
    //   count sentences
    int n_sentences = count_sentences(text);
    // printf("sentences: %d\n", n_sentences);
    //   compute the Coleam Liau Index
    float L = ((float) n_letters / (float) n_words) * 100; // Type casting is applied here (float)
    // printf("L: %f\n",L);
    float S = ((float) n_sentences / (float) n_words) * 100;
    // printf("S: %f\n", S);
    float index = (0.0588 * L - 0.296 * S - 15.8);
    // printf("index: %f\n", index);
    //   print the grade level
    int grade = round(index);
    if (index < 16 && index > 1)
    {
        printf("Grade %d\n", grade);
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
}
int count_letters(string txt)
{
    int n = strlen(txt);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!isalpha(txt[i])) // check wheter if a character is alphabetic
        {
            count++;
        }
    }
    int num = n - count;
    // printf("Number of letters: %i\n", n - count);
    return num;
}
int count_words(string txt)
{
    int n = strlen(txt);
    int count = 0;
    for (int i = 0; i < n + 1; i++) // here I add +1 to go one place far form the len of the string
    {
        if (txt[i] == ' ' || txt[i] == '\0') // compare if there is an space or the text has finished
        {
            count++;
        }
    }
    return count;
}
int count_sentences(string txt)
{
    int n = strlen(txt);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (txt[i] == '?' || txt[i] == '!' || txt[i] == '.') // These simbols (?, !, .) indicate the end of a sentences
        {
            count++;
        }
    }
    return count;
}
