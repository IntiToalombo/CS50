#include "cs50.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./pdf filename.pdf\n");
        return 1;
    }
    char *file = argv[1]; // The file to open and read
    // Opne the file in read mode (just to read)
    FILE *f = fopen(file, "r"); // FILE *f  tells where the file exactly is in memory
    if (f == NULL)              // check if the file's name matchs with a existing file
    {
        printf("File not found!\n");
        return 0;
    }
    // Create the buffer to hold the four bytes from the file
    uint8_t buffer[4]; // uint8_t is 8 bits long only positive
    char *pdf = "%PDF";
    // Read four bytes from the file into the buffer
    fread(buffer, 1, sizeof(buffer), f);
    for (int i = 0; i < 4; i++)
    {
        // print the four bytes from the buffer
        printf("%i\n", buffer[i]); // print what we have inside the buffer (the first four bytes on the file)
    }
    bool isPDFfile = true; // set true if a file is PDF file
    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != pdf[i]) // Check if each byte readed matchs with string pdf
        {
            isPDFfile = false;
            break;
        }
    }
    if (isPDFfile)
    {
        printf("%s is a PDF file.\n", file);
    }
    else
    {
        printf("%s is not a PDF file.\n", file);
    }

    // Close the file
    fclose(f);
}
