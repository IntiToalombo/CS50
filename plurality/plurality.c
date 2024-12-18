#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }
    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    // Iterate over each candidate
    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp(candidates[j].name, name) == 0)
        {
            candidates[j].votes = candidates[j].votes + 1;
            return true;
        }
    }
    // Check if candidate's name matches given name
    // If yes, increment candidate's votes and return true
    // If no match, return false
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    // Find the maximum number of votes
    int maxvotes = 0, winner = 0, cont = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > maxvotes)
        {
            maxvotes = candidates[i].votes;
            cont = 1;
            winner = i;
        }
        if(candidates[i].votes == maxvotes)
        {
            cont ++;
            winner = i;
        }
    }
    // Print the candidate (or candidates) with maximum votes
    if(cont > 1)
    {
        for(int k = 0; k < candidate_count; k++)
        {
            if(candidates[k].votes == maxvotes)
            {
                printf("%s\n", candidates[k].name);
            }
        }
    }
    return;
}
// By: Inti
