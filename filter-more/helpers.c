#include "helpers.h"
#include <math.h>
#include <stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    double average = 0.000;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // average of R, G, B pixels.
            average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0000;
            // update pixel values R = G = B
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = round(average);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blur_img[height][width];
    int count, avgR, avgG, avgB, sumRed, sumGreen, sumBlue;
    // iteration in the entire image
    for (int i = 0; i < height; i++) // iteration in rows
    {
        for (int j = 0; j < width; j++) // iteration in columns
        {
            count = 0;
            avgR = 0, sumRed = 0;
            avgG = 0, sumGreen = 0;
            avgB = 0, sumBlue = 0;
            // iteration in 3 x 3 pixels
            for (int r = -1; r < 2; r++) // iteration in rows
            {
                for (int c = -1; c < 2; c++) // iteration in colums
                {
                    // condition to extract RGB values only if the pixel exists
                    if ((i + r) >= 0 && (i + r) < height && (j + c) >= 0 && (j + c) < width)
                    {
                        // r and c will vary between -1 and 1 where
                        sumRed = sumRed + image[i + r][j + c].rgbtRed;
                        sumGreen = sumGreen + image[i + r][j + c].rgbtGreen;
                        sumBlue = sumBlue + image[i + r][j + c].rgbtBlue;
                        // count if the pixel exists
                        count++;
                    }
                }
            }
            // obtain RGB average values
            avgR = round((float) sumRed / (float) count);
            avgG = round((float) sumGreen / (float) count);
            avgB = round((float) sumBlue / (float) count);
            // update average of RGB in blurimage
            blur_img[i][j].rgbtRed = avgR;
            blur_img[i][j].rgbtGreen = avgG;
            blur_img[i][j].rgbtBlue = avgB;
            // image[i][j] = blur_img[i][j]; Do not update original image in this loop becuase it gets updated with other values
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = blur_img[i][j];
            // printf("%p ", &image[i][j].rgbtRed);
        }
    }
    return;
}

// edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    RGBTRIPLE edge_img[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRx = 0, sumGx = 0, sumBx = 0;
            int sumRy = 0, sumGy = 0, sumBy = 0;
            // loop in 3 x 3 image
            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    // condition for work with only existing values
                    if ((i + r) >= 0 && (i + r) < height && (j + c) >= 0 && (j + c) < width)
                    {
                        // compute with Gx kernel
                        sumRx += (image[i + r][j + c].rgbtRed * gx[r + 1][c + 1]);
                        sumGx += (image[i + r][j + c].rgbtGreen * gx[r + 1][c + 1]);
                        sumBx += (image[i + r][j + c].rgbtBlue * gx[r + 1][c + 1]);
                        // compute with Gy kernel
                        sumRy += (image[i + r][j + c].rgbtRed * gy[r + 1][c + 1]);
                        sumGy += (image[i + r][j + c].rgbtGreen * gy[r + 1][c + 1]);
                        sumBy += (image[i + r][j + c].rgbtBlue * gy[r + 1][c + 1]);
                    }
                }
            }

            // Normalize and round
            int sumR = round(sqrt(sumRx * sumRx + sumRy * sumRy));
            int sumG = round(sqrt(sumGx * sumGx + sumGy * sumGy));
            int sumB = round(sqrt(sumBx * sumBx + sumBy * sumBy));
            sumR = (sumR > 255) ? 255 : sumR;
            sumG = (sumG > 255) ? 255 : sumG;
            sumB = (sumB > 255) ? 255 : sumB;
            // Update RGB values in edge image
            edge_img[i][j].rgbtRed = sumR;
            edge_img[i][j].rgbtGreen = sumG;
            edge_img[i][j].rgbtBlue = sumB;
        }
    }

    // Update values in the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = edge_img[i][j];
        }
    }

    return;
}
/*CS50 Harvard Course. Author: Inti Toalombo, Ecuador-Hungary*/
