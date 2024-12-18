#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average = 0;
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rgb[3];
            rgb[0] = image[i][j].rgbtRed;
            rgb[1] = image[i][j].rgbtGreen;
            rgb[2] = image[i][j].rgbtBlue;
            // Take average of red, green, and blue
            average = round(((float) rgb[0] + (float) rgb[1] + (float) rgb[2]) / 3.0);
            // update pixel values
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed[3] = {0.393, 0.769, 0.189};   // values for sepia red
    float sepiaGreen[3] = {0.349, 0.686, 0.168}; // values for sepia green
    float sepiaBlue[3] = {0.272, 0.534, 0.131};  // values for sepia blue
    // iteration trough row and columns
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Sepia Red
            int red = round((float) image[i][j].rgbtRed * sepiaRed[0] + (float) image[i][j].rgbtGreen * sepiaRed[1] +
                            (float) image[i][j].rgbtBlue * sepiaRed[2]);
            if (red > 255) // ensure if the value is between 0 and 255
            {
                red = 255;
            }
            // Sepia Green
            int green = round((float) image[i][j].rgbtRed * sepiaGreen[0] + (float) image[i][j].rgbtGreen * sepiaGreen[1] +
                              (float) image[i][j].rgbtBlue * sepiaGreen[2]);
            if (green > 255)
            {
                green = 255;
            }
            // Sepia Blue
            int blue = round((float) image[i][j].rgbtRed * sepiaBlue[0] + (float) image[i][j].rgbtGreen * sepiaBlue[1] +
                             (float) image[i][j].rgbtBlue * sepiaBlue[2]);
            if (blue > 255)
            {
                blue = 255;
            }
            // update pixels values
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // iteration trough rows and columns
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++) // to avoid reflect pixels twice
        {
            // swap pixels
            RGBTRIPLE tempPx = image[i][j];        // create a temp variable of the same type
            image[i][j] = image[i][width - j - 1]; // substract 1 because 10 - 0 - 1 = 9. To avoid have 10 en j
            image[i][width - j - 1] = tempPx;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create a copy of the original image
    RGBTRIPLE copy_img[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy_img[i][j] = image[i][j];
        }
    }
    // blur middles
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((i != 0 || i != (height - 1)) && (j != (width - 1) || i != 0))
            {
                // compute values for middle's pixels
                int red = copy_img[i - 1][j - 1].rgbtRed + copy_img[i - 1][j].rgbtRed + copy_img[i - 1][j + 1].rgbtRed +
                          copy_img[i][j - 1].rgbtRed + copy_img[i][j].rgbtRed + copy_img[i][j + 1].rgbtRed +
                          copy_img[i + 1][j - 1].rgbtRed + copy_img[i + 1][j].rgbtRed + copy_img[i + 1][j + 1].rgbtRed;
                int green = copy_img[i - 1][j - 1].rgbtGreen + copy_img[i - 1][j].rgbtGreen + copy_img[i - 1][j + 1].rgbtGreen +
                            copy_img[i][j - 1].rgbtGreen + copy_img[i][j].rgbtGreen + copy_img[i][j + 1].rgbtGreen +
                            copy_img[i + 1][j - 1].rgbtGreen + copy_img[i + 1][j].rgbtGreen + copy_img[i + 1][j + 1].rgbtGreen;
                int blue = copy_img[i - 1][j - 1].rgbtBlue + copy_img[i - 1][j].rgbtBlue + copy_img[i - 1][j + 1].rgbtBlue +
                           copy_img[i][j - 1].rgbtBlue + copy_img[i][j].rgbtBlue + copy_img[i][j + 1].rgbtBlue +
                           copy_img[i + 1][j - 1].rgbtBlue + copy_img[i + 1][j].rgbtBlue + copy_img[i + 1][j + 1].rgbtBlue;
                // round to the nearest integer
                int averageRed = round((float) red / 9.0);
                int averageGreen = round((float) green / 9.0);
                int averageBlue = round((float) blue / 9.0);
                // Update pixels values
                image[i][j].rgbtRed = averageRed;
                image[i][j].rgbtGreen = averageGreen;
                image[i][j].rgbtBlue = averageBlue;
            }
        }
    }
    // blur borders - edge
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // top edge
            if ((i == 0) && (j != 0 || j != (width - 1)))
            {
                int red = copy_img[i][j].rgbtRed + copy_img[i][j + 1].rgbtRed + copy_img[i + 1][j + 1].rgbtRed +
                          copy_img[i + 1][j].rgbtRed + copy_img[i + 1][j - 1].rgbtRed + copy_img[i][j - 1].rgbtRed;

                int green = copy_img[i][j].rgbtGreen + copy_img[i][j + 1].rgbtGreen + copy_img[i + 1][j + 1].rgbtGreen +
                            copy_img[i + 1][j].rgbtGreen + copy_img[i + 1][j - 1].rgbtGreen + copy_img[i][j - 1].rgbtGreen;

                int blue = copy_img[i][j].rgbtBlue + copy_img[i][j + 1].rgbtBlue + copy_img[i + 1][j + 1].rgbtBlue +
                           copy_img[i + 1][j].rgbtBlue + copy_img[i + 1][j - 1].rgbtBlue + copy_img[i][j - 1].rgbtBlue;
                int averageRed = round((float) red / 6.0);
                int averageGreen = round((float) green / 6.0);
                int averageBlue = round((float) blue / 6.0);
                image[i][j].rgbtRed = averageRed;
                image[i][j].rgbtGreen = averageGreen;
                image[i][j].rgbtBlue = averageBlue;
            }
            // right edge
            if ((i != (height - 1) || i != 0) && (j == (width - 1)))
            {
                int red = copy_img[i][j].rgbtRed + copy_img[i + 1][j].rgbtRed + copy_img[i + 1][j - 1].rgbtRed +
                          copy_img[i][j - 1].rgbtRed + copy_img[i - 1][j - 1].rgbtRed + copy_img[i - 1][j].rgbtRed;
                int green = copy_img[i][j].rgbtGreen + copy_img[i + 1][j].rgbtGreen + copy_img[i + 1][j - 1].rgbtGreen +
                            copy_img[i][j - 1].rgbtGreen + copy_img[i - 1][j - 1].rgbtGreen + copy_img[i - 1][j].rgbtGreen;
                int blue = copy_img[i][j].rgbtBlue + copy_img[i + 1][j].rgbtBlue + copy_img[i + 1][j - 1].rgbtBlue +
                           copy_img[i][j - 1].rgbtBlue + copy_img[i - 1][j - 1].rgbtBlue + copy_img[i - 1][j].rgbtBlue;
                int averageRed = round((float) red / 6.0);
                int averageGreen = round((float) green / 6.0);
                int averageBlue = round((float) blue / 6.0);
                image[i][j].rgbtRed = averageRed;
                image[i][j].rgbtGreen = averageGreen;
                image[i][j].rgbtBlue = averageBlue;
            }
            // bottom edge
            if ((i == (height - 1)) && (j > 0 || j < (width - 1)))
            {
                int red = copy_img[i][j].rgbtRed + copy_img[i][j - 1].rgbtRed + copy_img[i - 1][j - 1].rgbtRed +
                          copy_img[i - 1][j].rgbtRed + copy_img[i - 1][j + 1].rgbtRed + copy_img[i][j + 1].rgbtRed;

                int green = copy_img[i][j].rgbtGreen + copy_img[i][j - 1].rgbtGreen + copy_img[i - 1][j - 1].rgbtGreen +
                            copy_img[i - 1][j].rgbtGreen + copy_img[i - 1][j + 1].rgbtGreen + copy_img[i][j + 1].rgbtGreen;

                int blue = copy_img[i][j].rgbtBlue + copy_img[i][j - 1].rgbtBlue + copy_img[i - 1][j - 1].rgbtBlue +
                           copy_img[i - 1][j].rgbtBlue + copy_img[i - 1][j + 1].rgbtBlue + copy_img[i][j + 1].rgbtBlue;
                int averageRed = round((float) red / 6.0);
                int averageGreen = round((float) green / 6.0);
                int averageBlue = round((float) blue / 6.0);
                image[i][j].rgbtRed = averageRed;
                image[i][j].rgbtGreen = averageGreen;
                image[i][j].rgbtBlue = averageBlue;
            }
            // left edge
            if ((i != 0 || i != (height - 1)) && (j == 0))
            {
                int red = copy_img[i][j].rgbtRed + copy_img[i - 1][j].rgbtRed + copy_img[i - 1][j + 1].rgbtRed +
                          copy_img[i][j + 1].rgbtRed + copy_img[i + 1][j + 1].rgbtRed + copy_img[i + 1][j].rgbtRed;
                int green = copy_img[i][j].rgbtGreen + copy_img[i - 1][j].rgbtGreen + copy_img[i - 1][j + 1].rgbtGreen +
                            copy_img[i][j + 1].rgbtGreen + copy_img[i + 1][j + 1].rgbtGreen + copy_img[i + 1][j].rgbtGreen;
                int blue = copy_img[i][j].rgbtBlue + copy_img[i - 1][j].rgbtBlue + copy_img[i - 1][j + 1].rgbtBlue +
                           copy_img[i][j + 1].rgbtBlue + copy_img[i + 1][j + 1].rgbtBlue + copy_img[i + 1][j].rgbtBlue;
                int averageRed = round((float) red / 6.0);
                int averageGreen = round((float) green / 6.0);
                int averageBlue = round((float) blue / 6.0);
                image[i][j].rgbtRed = averageRed;
                image[i][j].rgbtGreen = averageGreen;
                image[i][j].rgbtBlue = averageBlue;
            }
        }
    }
    // blur corners
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // top left corner
            if (i == 0 && j == 0)
            {
                int red = copy_img[i][j].rgbtRed + copy_img[i][j + 1].rgbtRed + copy_img[i + 1][j + 1].rgbtRed +
                          copy_img[i + 1][j].rgbtRed;
                int green = copy_img[i][j].rgbtGreen + copy_img[i][j + 1].rgbtGreen + copy_img[i + 1][j + 1].rgbtGreen +
                            copy_img[i + 1][j].rgbtGreen;
                int blue = copy_img[i][j].rgbtBlue + copy_img[i][j + 1].rgbtBlue + copy_img[i + 1][j + 1].rgbtBlue +
                           copy_img[i + 1][j].rgbtBlue;
                // round average pixel value
                int averageRed = round((float) red / 4.0);
                int averageGreen = round((float) green / 4.0);
                int averageBlue = round((float) blue / 4.0);
                // update values in copy image
                copy_img[i][j].rgbtRed = averageRed;
                copy_img[i][j].rgbtGreen = averageGreen;
                copy_img[i][j].rgbtBlue = averageBlue;
                // update values in originial image
                image[i][j] = copy_img[i][j];
            }
            // top rigth corner
            if (i == 0 && j == (width - 1))
            {
                int red = copy_img[i][j].rgbtRed + copy_img[i + 1][j].rgbtRed + copy_img[i + 1][j - 1].rgbtRed +
                          copy_img[i][j - 1].rgbtRed;
                int green = copy_img[i][j].rgbtGreen + copy_img[i + 1][j].rgbtGreen + copy_img[i + 1][j - 1].rgbtGreen +
                            copy_img[i][j - 1].rgbtGreen;
                int blue = copy_img[i][j].rgbtBlue + copy_img[i + 1][j].rgbtBlue + copy_img[i + 1][j - 1].rgbtBlue +
                           copy_img[i][j - 1].rgbtBlue;
                // round average pixel value
                int averageRed = round((float) red / 4.0);
                int averageGreen = round((float) green / 4.0);
                int averageBlue = round((float) blue / 4.0);
                // update values in copy image
                copy_img[i][j].rgbtRed = averageRed;
                copy_img[i][j].rgbtGreen = averageGreen;
                copy_img[i][j].rgbtBlue = averageBlue;
                // update values in original image
                image[i][j] = copy_img[i][j];
            }
            // bottom rigth corner
            if (i == (height - 1) && j == (width - 1))
            {
                int red = copy_img[i][j].rgbtRed + copy_img[i][j - 1].rgbtRed + copy_img[i - 1][j - 1].rgbtRed +
                          copy_img[i - 1][j].rgbtRed;
                int green = copy_img[i][j].rgbtGreen + copy_img[i][j - 1].rgbtGreen + copy_img[i - 1][j - 1].rgbtGreen +
                            copy_img[i - 1][j].rgbtGreen;
                int blue = copy_img[i][j].rgbtBlue + copy_img[i][j - 1].rgbtBlue + copy_img[i - 1][j - 1].rgbtBlue +
                           copy_img[i - 1][j].rgbtBlue;
                // round average pixel values
                int averageRed = round((float) red / 4.0);
                int averageGreen = round((float) green / 4.0);
                int averageBlue = round((float) blue / 4.0);
                // update values in copy image
                copy_img[i][j].rgbtRed = averageRed;
                copy_img[i][j].rgbtGreen = averageGreen;
                copy_img[i][j].rgbtBlue = averageBlue;
                // update values in oiriginal image
                image[i][j] = copy_img[i][j];
            }
            // bottom left corner
            if (i == (height - 1) & j == 0)
            {
                int red = copy_img[i][j].rgbtRed + copy_img[i - 1][j].rgbtRed + copy_img[i - 1][j + 1].rgbtRed +
                          copy_img[i][j + 1].rgbtRed;
                int green = copy_img[i][j].rgbtGreen + copy_img[i - 1][j].rgbtGreen + copy_img[i - 1][j + 1].rgbtGreen +
                            copy_img[i][j + 1].rgbtGreen;
                int blue = copy_img[i][j].rgbtBlue + copy_img[i - 1][j].rgbtBlue + copy_img[i - 1][j + 1].rgbtBlue +
                           copy_img[i][j + 1].rgbtBlue;
                // round average pixel values
                int averageRed = round((float) red / 4.0);
                int averageGreen = round((float) green / 4.0);
                int averageBlue = round((float) blue / 4.0);
                // update values in copy image
                copy_img[i][j].rgbtRed = averageRed;
                copy_img[i][j].rgbtGreen = averageGreen;
                copy_img[i][j].rgbtBlue = averageBlue;
                // update values in oiriginal image
                image[i][j] = copy_img[i][j];
            }
        }
    }
    return;
}
/*CS50 Harvard Course. Author: Inti Toalombo, Ecuador-Hungary*/
