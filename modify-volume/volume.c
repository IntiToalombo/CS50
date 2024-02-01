// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44; // The header of a WAV is 44 bytes long.

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // Copy header from input file to output file
    uint8_t header[HEADER_SIZE]; // unint8_t stores 8 bits unsigned integer.
    // fread(where to read,size of type of data to read in bytes,number of those types to read at once, from where to read)
    fread(header, sizeof(header), 1, input);
    fwrite(header, sizeof(header), 1, output);
    // Read samples from input file and write updated data to output file
    int16_t samples; // int16_t stores 16 bits signed integer (+ or -)
    while (fread(&samples, sizeof(samples), 1, input))
    {
        // printf("Samples: %d\n", samples);
        samples = samples * factor; // update volume of sample
        fwrite(&samples, sizeof(samples), 1, output);
    }
    // Close files
    fclose(input);
    fclose(output);
}
/*CS50 Harvard Course. Author: Inti Toalombo, Ecuador-Hungary*/

