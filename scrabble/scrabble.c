#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// int POINTS[] = {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p,  q,  r, s, t, u, v, w, x, y, z};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    // TODO: Print the winner
    // printf("Score1: %i\n", score1);
    // printf("Score2: %i\n", score2);
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
}
int compute_score(string word)
{
    // string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int sum = 0;

    for (int j = 0; j < strlen(word); j++) //  it execute unitl reach the word's lenght
    {
        word[j] = tolower(word[j]);          // convert each letter of the word to lowercase letters
        if (word[j] >= 97 && word[j] <= 122) // condition for sum point if the word's letter is in the
                                             // range of ASCII code 97=a and 122 = z.
        {
            int position = word[j] - 'a' + 1;  // find the word's letter position, substracting 'a' = 97 + 1.
            int points = POINTS[position - 1]; // assigning points for each position of the word's letter
            // printf("%c = %i\n", word[j], points); // print word's chars and points assigned to each one
            sum += points; // add points
        }
        else
        {
            sum += 0; // if the letter isn't in the range stablished before
                      // it won't add
        }
    }
    // printf("Points: %i\n", sum);

    // TODO: Compute and return score for string

    return sum; // return sum of points
}
// By: Inti Toalombo
