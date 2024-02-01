#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    // check correct usage
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }
    // open memory card to read
    char *memory = argv[1];
    FILE *mry = fopen(memory, "r");
    // check if card.raw is open correctly
    if (mry == NULL)
    {
        printf("Error: Could not open %s!\n", argv[1]);
        return 2;
    }
    // creat a buffer to read temporaly data from card.
    const int BLOCKSIZE = 512; // card stores data in block of 512 bytes
    uint8_t buffer[BLOCKSIZE]; // create a buffer with 512 bytes size
    // create a name for output file
    char out_img[10]; // a string with enoug space to assign names to recover images
    int count = 0;    // counter for files' names
    // create a file for recover images
    FILE *outptr = NULL;
    // read until end of the card
    while (fread(buffer, BLOCKSIZE, 1, mry) == 1)
    {
        // if starts of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0) // the las conditional uses bitwise arithmetic to look at the first four bits of this byte
        {
            // if has been create a recovered image file it closes the file
            if (count > 0)
            {
                fclose(outptr);
            }
            // give name for the nth.jpg image
            sprintf(out_img, "%03i.jpg", count);
            // open a file in write mode for recover images
            outptr = fopen(out_img, "w");
            // check if recover image file has been created correctly
            if (outptr == NULL)
            {
                printf("Error: File %s has not been created!\n", out_img);
                return 3;
            }
            count++;
        }
        // write data in recover image from buffer
        if (outptr != NULL)
        {
            fwrite(buffer, BLOCKSIZE, 1, outptr);
        }
    }
    // close the last recover image file
    fclose(outptr);
    // close card file
    fclose(mry);
    return 0;
}
/*CS50 Harvard Course. Author: Inti Toalombo, Ecuador-Hungary*/
