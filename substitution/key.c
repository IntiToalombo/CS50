#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string key = "jtrekyavogdxpsncuizlfbmwhq";
    for(int i = 0; i < 26; i++)
    {
        int positionk = key[i] - 'a' + 1;
        int positiona = alphabet[i] - 'a' + 1;
        key[i] = alphabet[i] + (positionk - positiona);
        printf("%i %c;", key[i], key[i]);
    }
}
