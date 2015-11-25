//A function that creates a 2x2 greyish bitmap that I use for test purposes
#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

//Prototypes
void defineBF(BITMAPFILEHEADER * bf);
void defineBI(BITMAPINFOHEADER * bi);

int main(int argc, char * argv[]){
    //Check for proper usage 
    if (argc != 2){
        printf("Usage: ./createbmp outfile.bmp\n");
        return 0;
    }
    //Create file with the name specified in the parameter argv[1]
    FILE * outptr = fopen(argv[1], "w");
    if (outptr == NULL){
        printf("Could not create file\n");
    }
    //Create bitmap headers
    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;
    //Fill the headers with information
    defineBF(&bf);
    defineBI(&bi);
    //Write the headers to the new bitmap file 
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    //Determine padding
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    //Write a pixel line to the output file (height)
    for (int i = 0; i < abs(bi.biHeight); i++){
        //Write pixels to the output file (width)
        for (int j = 0; j < bi.biWidth; j++){
            //Temporary storage for the color triplet
            RGBTRIPLE triple;
            //Set RGB to the triplet
            triple.rgbtRed = 0x60;
            triple.rgbtGreen = 0x60;
            triple.rgbtBlue = 0x60;
            if(j>0){
                triple.rgbtRed = 0x61;
                triple.rgbtGreen = 0x61;
                triple.rgbtBlue = 0x61;   
            }
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }
        //Write padding to the output file
        for (int k = 0; k < padding; k++){
            fputc(0x00, outptr);
        }
    }
    //Close output file
    fclose(outptr);
}
//The function to fill in BITMAPFILEHEADER
void defineBF(BITMAPFILEHEADER * bf){
    bf->bfType = 0x4d42;
    bf->bfSize = 12 + 54;
    bf->bfReserved1 = 0;
    bf->bfReserved2 = 0;
    bf->bfOffBits = 54;    
}
//The function to fill in BITMAPINFOHEADER
void defineBI(BITMAPINFOHEADER * bi){
    bi->biSize = 40;
    bi->biWidth = 2;
    bi->biHeight = -2;
    bi->biPlanes = 1;
    bi->biBitCount = 24;
    bi->biCompression = 0;
    bi->biSizeImage = 12;
    bi->biXPelsPerMeter = 2834;
    bi->biYPelsPerMeter = 2834;
    bi->biClrUsed = 0;
}
