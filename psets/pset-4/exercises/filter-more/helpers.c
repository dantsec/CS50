#include "helpers.h"
// ROUND, SQRT
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            temp[i][j] = image[i][j];

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            float Gx_red;
            float Gx_blue;
            float Gx_green;
            float Gy_red;
            float Gy_blue;
            float Gy_green;

            Gx_red = Gx_blue = Gx_green = Gy_red = Gy_blue = Gy_green = 0;

            for(int k = -1; k < 2; k++) {
                for(int l = -1; l < 2; l++) {
                    if (i + k < 0 || i + k >= height)
                        continue;
                    if (j + l < 0 || j + l >= width)
                        continue;

                    Gx_red   += temp[i + k][j + l].rgbtRed   * Gx[k + 1][l + 1];
                    Gx_green += temp[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];
                    Gx_blue  += temp[i + k][j + l].rgbtBlue  * Gx[k + 1][l + 1];
                    Gy_red   += temp[i + k][j + l].rgbtRed   * Gy[k + 1][l + 1];
                    Gy_green += temp[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];
                    Gy_blue  += temp[i + k][j + l].rgbtBlue  * Gy[k + 1][l + 1];
                }
            }

            int red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int green = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

            if (red > 255)
                red = 255;
            if (green > 255)
                green = 255;
            if (blue > 255)
                blue = 255;

            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }

    return;
}
