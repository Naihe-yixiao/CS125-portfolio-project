// CS125 PORTFOLIO PROJECT
// MEMBERS: VIREAK LA & HONGSRENG PHENG
// SECTION 2

// Usage: ./filter -filterOption inputfile.bmp
// The output file will be named to "filterOption.bmp"

// ========================================================================= //
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "types.h"

using namespace std;

bool is24_bit_BMP(BITMAPFILEHEADER bf, BITMAPINFOHEADER bi);
bool is_valid_filter(string filterOpt, string filters[]);

int main(int argc, char** argv)
{
    // Define allowed filters
    string filters[] = {"-horizontal", "-vertical", "-blur", "-edge", "-greyscale", "-red", "-mix"};

    // Ensure proper usage
    if (argc < 3)
    {
        cerr << "Usage: ./filter -filterOption inputfile.bmp\n";
        return 1;
    }

    // Validate input filter
    char* filterOpt = argv[1];
    if (!is_valid_filter(filterOpt, filters))
    {
        cerr << "Invalid filter\n";
        return 2;
    }

    // Validate input file
    if (argv[2][strlen(argv[2]) - 2] != 'p' && argv[2][strlen(argv[2]) - 3] != 'm' &&
        argv[2][strlen(argv[2]) - 4] != 'b' && argv[2][strlen(argv[2]) - 5] != '.' &&
        strlen(argv[2]) < 5)
    {
        cerr << "Invalid file\n";
        return 3;
    }

    // Open the input file
    FILE *inFile = fopen(argv[2], "r");
    if (inFile == NULL)
    {
        cerr << "File cannot be openned!\n";
        return 4;
    }

    // Read input file's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inFile);

    // Read input file's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inFile);

    // Ensure input file is a 24-bit uncompressed BMP 4.0
    if (!is24_bit_BMP(bf, bi))
    {
        fclose(inFile);
        cerr << "Unsupported file format.\n";
        return 5;
    }

    // Get the height and width of the image and declare the pixel grid representation
    int height = abs(bi.biHeight);
    int width = abs(bi.biWidth);
    RGBTRIPLE pixel[height][width];

    // Calculate extra padding 
    int padding = (width * (4 - sizeof(RGBTRIPLE)) % 4);

    // Iterate over each row and skip the padding
    for (int i = 0; i < height; i++)
    {
        fread(pixel[i], sizeof(RGBTRIPLE), width, inFile);
        fseek(inFile, padding, SEEK_CUR);
    }

    if (filterOpt == filters[0])
    {
        // Run horizontal flip on the pixels
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (j < width - 1 -j)
                {
                    RGBTRIPLE temp = pixel[i][j];

                    pixel[i][j] = pixel[i][width - 1 - j];

                    pixel[i][width - 1 - j] = temp;
                }
            }
        }
    }
    else if (filterOpt == filters[1])
    {
        // Run vertical flip on the pixels
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (i < height - 1 - i)
                {
                    RGBTRIPLE temp = pixel[i][j];

                    pixel[i][j] = pixel[height - 1 - i][j];

                    pixel[height - 1 - i][j] = temp;
                }
            }
        }
    }
    else if (filterOpt == filters[2])
    {
        // Run blur on the pixel
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int counter = 1;
                int allBlue = pixel[i][j]. rgbtBlue;
                int allRed = pixel[i][j]. rgbtRed;
                int allGreen = pixel[i][j]. rgbtGreen;

                if (i > 0) // has upper
                {
                    allBlue += pixel[i - 1][j]. rgbtBlue;
                    allRed += pixel[i - 1][j]. rgbtRed;
                    allGreen += pixel[i - 1][j]. rgbtGreen;
                    counter++;
                }
                if (i < height - 1) // has lower
                {
                    allBlue += pixel[i + 1][j]. rgbtBlue;
                    allRed += pixel[i + 1][j]. rgbtRed;
                    allGreen += pixel[i + 1][j]. rgbtGreen;
                    counter++;
                }
                if (i > 0 && j > 0) // has upper left
                {
                    allBlue += pixel[i - 1][j - 1]. rgbtBlue;
                    allRed += pixel[i - 1][j - 1]. rgbtRed;
                    allGreen += pixel[i - 1][j - 1]. rgbtGreen;
                    counter++;
                }
                if (i > 0 && j < width - 1) // has upper right
                {
                    allBlue += pixel[i - 1][j + 1]. rgbtBlue;
                    allRed += pixel[i - 1][j + 1]. rgbtRed;
                    allGreen += pixel[i - 1][j + 1]. rgbtGreen;
                    counter++;
                }
                if (j < width - 1) // has right
                {
                    allBlue += pixel[i][j + 1]. rgbtBlue;
                    allRed += pixel[i][j + 1]. rgbtRed;
                    allGreen += pixel[i][j + 1]. rgbtGreen;
                    counter++;
                }
                if (j > 0) // has left
                {
                    allBlue += pixel[i][j - 1]. rgbtBlue;
                    allRed += pixel[i][j - 1]. rgbtRed;
                    allGreen += pixel[i][j - 1]. rgbtGreen;
                    counter++;
                }
                if (i < height - 1 && j > 0) // has lower left
                {
                    allBlue += pixel[i + 1][j - 1]. rgbtBlue;
                    allRed += pixel[i + 1][j - 1]. rgbtRed;
                    allGreen += pixel[i + 1][j - 1]. rgbtGreen;
                    counter++;
                }
                if (i < height - 1 && j < width - 1) // has lower right
                {
                    allBlue += pixel[i + 1][j + 1]. rgbtBlue;
                    allRed += pixel[i + 1][j + 1]. rgbtRed;
                    allGreen += pixel[i + 1][j + 1]. rgbtGreen;
                    counter++;
                }
                // calculate the average
                pixel[i][j]. rgbtBlue = round(allBlue / (float) counter);
                pixel[i][j]. rgbtRed = round(allRed / (float) counter);
                pixel[i][j]. rgbtGreen = round(allGreen / (float) counter);
            }
        }
    }
    else if (filterOpt == filters[3])
    {
        // Run edge detection on the pixel
        //Define kernels
        int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
        int Gy[3][3] = {{-1, -2, -1}, {0,0,0}, {1, 2, 1}};

        // Allocate an array to store original pixels data and beyond-border pixels data
        RGBTRIPLE origin_image[height+2][width+2];

        // Populate original array and beyond-border array
        for (int i = 0; i < height + 2; i++)
        {
            for (int k = 0; k < width + 2; k++)
            {
                // If in border, initialize as origital pixels, otherwise initialize it to zero
                if (i < height + 1 && k > 0 && i > 0 && k < width + 1)
                {
                    origin_image[i][k]. rgbtBlue = pixel[i - 1][k - 1]. rgbtBlue;
                    origin_image[i][k]. rgbtGreen = pixel[i - 1][k - 1]. rgbtGreen;
                    origin_image[i][k]. rgbtRed = pixel[i - 1][k - 1]. rgbtRed;
                }
                else
                {
                    origin_image[i][k]. rgbtBlue = 0;
                    origin_image[i][k]. rgbtGreen = 0;
                    origin_image[i][k]. rgbtRed = 0;
                }
            }
        }

        // Run Sobel edge detection algorithm
        for (int i = 1; i <= height; i++)
        {
            for (int k = 1; k <= width; k++)
            {
                double gxRed = 0;
                double gxGreen = 0;
                double gxBlue = 0;
                double gyRed = 0;
                double gyGreen = 0;
                double gyBlue = 0;

                // Calculate Gx and Gy
                for (int j = 0; j < 3; j++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        gxRed += origin_image[i - 1 + j][k - 1 + l]. rgbtRed * Gx[j][l];
                        gxGreen += origin_image[i - 1 + j][k - 1 + l]. rgbtGreen * Gx[j][l];
                        gxBlue += origin_image[i - 1 + j][k - 1 + l]. rgbtBlue * Gx[j][l];

                        gyRed += origin_image[i - 1 + j][k - 1 + l]. rgbtRed * Gy[j][l];
                        gyGreen += origin_image[i - 1 + j][k - 1 + l]. rgbtGreen * Gy[j][l];
                        gyBlue += origin_image[i - 1 + j][k - 1 + l]. rgbtBlue * Gy[j][l];
                    }
                }

                // Calculate final value
                int totalRed, totalGreen, totalBlue;
                totalRed = min((int) (sqrt(pow(gxRed, 2) + pow(gyRed, 2))), 255);
                totalGreen = min((int) (sqrt(pow(gxGreen, 2) + pow(gyGreen, 2))), 255);
                totalBlue = min((int) (sqrt(pow(gxBlue, 2) + pow(gyBlue, 2))), 255);
                // Load the result of Gx and Gy into pixel
                pixel[i - 1][k - 1]. rgbtRed = totalRed;
                pixel[i - 1][k - 1]. rgbtGreen = totalGreen;
                pixel[i - 1][k - 1]. rgbtBlue = totalBlue;
            }
        }
    }
    else if (filterOpt == filters[4])
    {
        // Run greyscale on the pixel
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int average = (pixel[i][j].rgbtRed + pixel[i][j].rgbtGreen + pixel[i][j].rgbtBlue)/3;

                pixel[i][j].rgbtRed = average;
                pixel[i][j].rgbtGreen = average;
                pixel[i][j].rgbtBlue = average;
            }
        }
    }
    else if (filterOpt == filters[5])
    {
        // Run red on the pixel
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int average = (pixel[i][j].rgbtRed + pixel[i][j].rgbtGreen + pixel[i][j].rgbtBlue)/3;

                pixel[i][j].rgbtRed = average;
                pixel[i][j].rgbtGreen = 0;
                pixel[i][j].rgbtBlue = 0;
            }
        }
    }
    else if (filterOpt == filters[6])
    {
        // Run mix on the pixel
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int average = (pixel[i][j].rgbtRed + pixel[i][j].rgbtGreen + pixel[i][j].rgbtBlue)/3;
                if (j < (int) width/3)
                {
                    pixel[i][j].rgbtRed = 0;
                    pixel[i][j].rgbtGreen = average;
                    pixel[i][j].rgbtBlue = 0;
                }
                else if (j > (int) (2*width)/3)
                {
                    int average = (pixel[i][j].rgbtRed + pixel[i][j].rgbtGreen + pixel[i][j].rgbtBlue)/3;
                    pixel[i][j].rgbtRed = average;
                    pixel[i][j].rgbtGreen = 0;
                    pixel[i][j].rgbtBlue = 0;
                }
                else if (j > width)
                {
                    int average = (pixel[i][j].rgbtRed + pixel[i][j].rgbtGreen + pixel[i][j].rgbtBlue)/3;
                    pixel[i][j].rgbtRed = 0;
                    pixel[i][j].rgbtGreen = 0;
                    pixel[i][j].rgbtBlue = average;
                }
            }
        }
    }

    // Open outFile
    char *outFileName  = strcat(filterOpt, ".bmp");
    FILE *outFile = fopen(outFileName, "w");
    if (outFile == NULL)
    {
        cerr << "Output file cannot be created\n";
        return 6;
    }

    // Write file header and info header to outfile
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outFile);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outFile);

    // Write new pixels to outFile row by row and add padding
    for (int i = 0; i < height; i++)
    {
        fwrite(pixel[i], sizeof(RGBTRIPLE), width, outFile);
        for (int k = 0; k < padding; k++)
        {
            // Write null byte to complete padding
            fputc(0x00, outFile);
        }
    }

    // Close all the openned files
    fclose(outFile);
    fclose(inFile);
    return 0;
}

bool is24_bit_BMP(BITMAPFILEHEADER bf, BITMAPINFOHEADER bi)
{
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool is_valid_filter(string filterOpt, string filters[])
{
    for (int i = 0; i < 7; i++)
    {
        if (!filterOpt.compare(filters[i]))
        {
            return true;
        }
        else if (i == 6)
        {
            return false;
        }
    }
    return false;
}