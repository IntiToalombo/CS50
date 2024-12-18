/*
This program implements a substitution cipher
Example:
$./substitution JTREKYAVOGDXPSNCUIZLFBMWHQ
plaintext: HELLO
Ciphertext: VKXXN
Find the program's specifications here -> https://cs50.harvard.edu/x/2023/psets/2/substitution/
*/
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void cipher_text(string plaintext, string argvv); // cipher_text function calling
int main(int argc, string argv[]) // main function with 2 arguments , argc is number of command lines and argv is the key string
{
    // printf("%i:",n);
    if (argc != 2) // if command line is not 2
    {
        printf("usage: ./substitution key\n");
        return 1;
    }
    else
    {
        int n = strlen(argv[1]); // asign len of argv to n
        // Checkin the lenght of argv
        for (int i = 0, j = n; i < n;
             i++) // 2 for loop for verify every letter of argv if we use just one loop it just compare the first letter of argv
        {
            for (int k = 0; k < n; k++)
            {
                // check key lenght ABC
                // Key must contain 26 characters
                if (n != 26 && ((argv[1][k] >= 65 && argv[1][k] <= 90) || (argv[1][k] >= 97 && argv[1][k] <= 122)))
                {
                    printf("Key must contain 26 characters.\n");
                    return 1; // returning 1 means that there is an error and the programm can't continue
                    break;
                }
            }
        }
        // 1st condition: ABCDEFGHIJKLMNOPQRSTUVWXY2
        // Key must only contain alphabetic characters
        for (int i = 0, j = n; i < n; i++)
        {
            for (int k = 0; k < n; k++)
            {
                // printf("%c\n", argv[1][k]);
                if (n == 26 && ((argv[1][k] < 65 || argv[1][k] > 122) || (argv[1][k] > 90 && argv[1][k] < 97)))
                {
                    printf("key must only contain alphabetic characters.\n");
                    return 1; // returning 1 means that there is an error and the programm can't continue
                    break;
                }
            }
        }
        // 2d condition: ABCDEFGHIJKLMNOPQRSTUVWXYA
        // key must not cotain repeated characters
        for (int i = 0, j = n; i < n; i++)
        {
            for (int k = 0; k < n; k++)
            {
                // printf("%c\n",argv[1][l]);
                argv[1][i] = tolower(argv[1][i]); // transform each argv's letter to lowercase
                argv[1][k] = tolower(argv[1][k]); // transform each argv's letter to lowercase
                // printf("%c = %c\n",argv[1][i], argv[1][l]);
                if (((argv[1][k] >= 65 && argv[1][k] <= 90) || (argv[1][k] >= 97 && argv[1][k] <= 122)) &&
                    (argv[1][i] == argv[1][k]) && i != k)
                {
                    // printf("%c = %c\n",argv[1][i], argv[1][k]);
                    printf("Key must not contain repeated characters\n");
                    return 1; // returning 1 means that there is an error and the programm can't continue
                    break;
                }
            }
        }
        // valid condition to execute the cipher_text function
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < n; k++)
            {
                if (n == 26 && ((argv[1][k] >= 65 && argv[1][k] <= 90) || (argv[1][k] >= 97 && argv[1][k] <= 122)))
                {
                    string plaintext = get_string("Plaintext: \n");
                    cipher_text(plaintext, argv[1]);
                    return 0; // returning 0 means that the program match the properly conditions
                    break;
                }
            }
        }
    }
}

/*Function to change plaintext to ciphetext*/
void cipher_text(string plaintext, string argvv)
{
    printf("ciphertext: ");
    for (int j = 0; j < strlen(plaintext); j++)
    {
        int positiontext = 0;                           // To find the position on the alphabet of each plaintext's letter
        if (plaintext[j] >= 'A' && plaintext[j] <= 'Z') // position if letter is uppercase
        {
            positiontext = plaintext[j] - 'A' + 1;
        }
        else if (plaintext[j] >= 'a' && plaintext[j] <= 'z') // position if letter is lowercase
        {
            positiontext = plaintext[j] - 'a' + 1;
        }
        char ciphertext =
            argvv[positiontext - 1]; // asign each argument's letter to chipertext, subtract -1 becuase is advanced 1 position
        if (islower(plaintext[j]))   // if plaintext char is lowercase, ciphertext remains lowercase
        {
            ciphertext = tolower(ciphertext);
        }
        else // if plaintext is uppercase, ciphertext remains uppercase
        {
            ciphertext = toupper(ciphertext);
        }
        if (plaintext[j] >= 32 && plaintext[j] <= 64) // if plaintext contains no alphabetic characters it remains the same way
        {
            ciphertext = plaintext[j];
        }
        printf("%c", ciphertext); // print chipertext
    }
    printf("\n");
}
//By: Inti Toalombo
