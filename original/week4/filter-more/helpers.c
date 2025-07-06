#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
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
        for (int j = 0, middle = width / 2.0; j < middle; j++)
        {
            RGBTRIPLE temp_pixel = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp_pixel;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    // For every pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Counters
            int totalRed = 0, totalGreen = 0, totalBlue = 0;
            int totalPixels = 0;

            // For every surrounding pixel
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        totalRed += image[k][l].rgbtRed;
                        totalGreen += image[k][l].rgbtGreen;
                        totalBlue += image[k][l].rgbtBlue;
                        totalPixels++;
                    }
                }
            }

            // Average values
            totalRed = (int) round((float) totalRed / totalPixels);
            totalGreen = (int) round((float) totalGreen / totalPixels);
            totalBlue = (int) round((float) totalBlue / totalPixels);

            copy[i][j].rgbtRed = totalRed;
            copy[i][j].rgbtGreen = totalGreen;
            copy[i][j].rgbtBlue = totalBlue;
        }
    }

    // Set old arr to new arr
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // For every pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        //
                    }
                }
            }
        }
    }
}
