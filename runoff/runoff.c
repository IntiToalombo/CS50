#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1; // it gets the number of candidates entered as the argument
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1]; // it builts the candidates' names array
        candidates[i].votes = 0;          // number of votes of the candidates it begins at 0
        candidates[i].eliminated = false; // it begins as noneliminated
    }

    voter_count = get_int("Number of voters: "); // it asks to the user to enter number of candidates
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1); // j+1 is because to start at 1 since j = 0

            // Record vote, unless it's invalid
            if (!vote(i, j, name)) // it call vote functions, if name doesn't match with candidates[i].name prints invalid vote
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won) // won might be true or false, if won is true loop breaks.
        {
            break;
        }
        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated) // if candidates is not eliminated  the print winners' names.
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    // To avoid votes for the same candidate
    /* for(int i = 0; i < rank; i++)// rank = j  --> Number of candidates, voter = i --> Number of voters
        {
            for(int j = 0; j < rank; j++)
            {
                if(preferences[rank][i] == preferences[rank][j] && i != j)// check if the voter has already voted for the same
                {
                    printf("Invalid vote.\n");
                    break;
                }
            }
        }*/
    // To check if the ranked names are in the candidates' array.

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0) // it checks if the entered name matches with candidates array
        {
            preferences[voter][rank] = i; // update the voters preferences
            return true;
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    int candidate;
    // TODO
    for (int i = 0; i < voter_count; i++) // iterate trough voters
    {
        for (int j = 0; j < candidate_count; j++) // iterate troguht candidates
        {
            candidate = preferences[i][j];         // asign preferences to int candidate
            if (!candidates[candidate].eliminated) // it checks if the preference hasn't been elminated
            {
                candidates[candidate].votes++; // it counts candidate's votes
                break;                         // it is for  count only one vote, not countinue down in the ballot
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > voter_count / 2)             // check if a candidate has half + 1 votes to be the winner
        {
            printf("%s\n", candidates[i].name); //
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TO DO
    int min = voter_count; // The candidate who hasn't at least the total # of voter has to be eliminated
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated &&
            candidates[i].votes < min) // if candidate hasn't been eliminated  and has lower than the minimun votes
        {
            min = candidates[i].votes; // new minimum
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int cont = 0;
    int noneliminated = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        // if candidates have't been eliminated they are counted
        if (!candidates[i].eliminated)
        {
            noneliminated++;
        }
        // Candidates with the minimun votes are also counted
        if (candidates[i].votes == min)
        {
            cont++;
        }
    }
        // comparing noneliminated candidates and candidates with minimum votes
        if (noneliminated == cont)
        {
            return true;
        }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
//By: Inti
