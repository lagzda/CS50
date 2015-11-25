//A resize function built upon copy.c (Still unfinished)
#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char * argv[]){
    //Check for proper usage
    if (argc != 4){
        printf("Usage: ./resize.c n infile outfile\n");
        return 1;
    }
    //Remember the parameters
    char * infile = argv[2];
    char * outfile = argv[3];
    int factor = atoi(argv[1]);
    //Open readable file and check for NULL
    FILE * inptr = fopen(infile, "r");
    if (inptr == NULL){
        printf("Could not open file %s\n", infile);
        return 2;
    }
    //Create writeable file and check for NULL
    FILE * outptr = fopen(outfile, "w");
    if (outptr == NULL){
        printf("Could not create %s", outfile);
        fclose(inptr);
        return 3;
    }
    //Define file and info headers for the bitmap
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    //Check if infile is likely 24-bit uncommpresed BMP.
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
    bi.biBitCount != 24 || bi.biCompression != 0){
        fclose(outptr);
        fclose(inptr);
        printf("Unsupported file format");
        return 4;
    }
    //Modify headers by the factor given
    bf.bfSize = (bf.bfSize-54)*factor*factor+54;
    bi.biWidth *= factor;
    bi.biHeight *= factor;
    bi.biSizeImage *= factor*factor;
    //Write the output file's headers
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    //Determine padding before
    int paddingb = (4 - ((bi.biWidth/factor) * sizeof(RGBTRIPLE)) % 4) % 4;
    //Determine padding after
    int paddinga = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    //Iterate over scanlines original times because we will multiply lines as we add them
    for (int i = 0, biHeight = abs(bi.biHeight)/factor; i < biHeight;i++){
        //Write scanline factor times
        for (int z = 0; z < factor; z++){
        //Iterate over each pixel original times because we will multiply pixels as we add them
            for (int j = 0, biWidth = bi.biWidth / factor; j < biWidth; j++){
                //Temporary storage
                RGBTRIPLE triple;
                //Read the triple from input file
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                for (int k = 0; k < factor; k++){
                    //Write the triple to output file factor times
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);     
                }
            }
            //Seek/skip back to scanline if it's the last multiplied scanline
            if (z < factor - 1){
                fseek(inptr, -sizeof(RGBTRIPLE) * (bi.biWidth / factor), SEEK_CUR);
            }
            //Add the padding to output file
            for (int l = 0; l < paddinga; l++){
                fputc(0x00,outptr);
            }
        }
        //Seek/skip over padding in input file
        fseek(inptr, paddingb, SEEK_CUR);
    }
    //Close input file and output file
    fclose(inptr);
    fclose(outptr);
    return 0;   
}
