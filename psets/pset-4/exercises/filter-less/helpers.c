#include "helpers.h"
// ROUND
#include <math.h>
// MALLOC
#include <stdlib.h>
// MEMCPY
#include <string.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float grayscale = 0.0;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            grayscale = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = grayscale;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue;
    sepiaRed = sepiaGreen = sepiaBlue = 0;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            sepiaRed   = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            sepiaBlue  = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width / 2; j++) {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp ;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    memcpy(temp, image, sizeof(RGBTRIPLE) * height * width);

    for(int i = 0 ; i < height ; i++) {
        for(int j = 0 ; j < width ; j++) {
            float average = 0.0 ;

            int R = 0;
            int G = 0;
            int B = 0;

            for(int k = -1 ; k <= 1 ; k++) {
                for(int l = -1 ; l <= 1 ; l++) {
                    if(i + k != height && i + k != -1 && j + l != width && j + l != -1) {
                        R += temp[i + k][j + l].rgbtRed;
                        G += temp[i + k][j + l].rgbtGreen;
                        B += temp[i + k][j + l].rgbtBlue;

                        average++;
                    }
                }
            }

            image[i][j].rgbtRed = round(R / average) ;
            image[i][j].rgbtGreen = round(G / average) ;
            image[i][j].rgbtBlue = round(B / average) ;
        }
    }

    return;
}
