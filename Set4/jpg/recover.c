/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
typedef uint8_t BYTE;

//Prototypes
//Comparison function that checks if the 512 byte block's first bytes are the jpg signature
bool isJpg(BYTE bytes1[], BYTE bytes2[]);

int main(void)
{
    //Open the raw data file
    FILE * inptr = fopen("card.raw", "r");
    //Check if the file is not NULL
    if (inptr == NULL){
        printf("Could not open file\n");
        return 1;
    }
    //Initialise the two jpg signatures, buffer, output file pointer,
    //counter for filenames, and a temporary string name storage.
    BYTE beg1[4] = {0xff, 0xd8, 0xff, 0xe0};
    BYTE beg2[4] = {0xff, 0xd8, 0xff, 0xe1};
    BYTE buffer[512];
    FILE * outptr = NULL;
    int jpgCounter = 0;
    char jpgName[8];
    //While we can read elements of size 512 bytes
    while(fread(buffer, 512, 1, inptr)==1){
        //If the beginning of the 512 byte block matches the jpg signature... 
        if(isJpg(buffer,beg1) || isJpg(buffer,beg2)){
            //If we are already writing to a file close it
            if (outptr != NULL){
                fclose(outptr);
                outptr = NULL;
            }
            //Generate a name for the new jpg
            sprintf(jpgName, "%03i.jpg", jpgCounter);
            //Create the new jpg and check if successful
            outptr = fopen(jpgName, "w");
            if (outptr == NULL){
                printf("Could not create file\n");
                fclose(inptr);
                return 2;
            }
            //Write the 512 byte block into the new output file
            fwrite(buffer, 512, 1, outptr);
            //Increment jpg counter so the next filename would be one higher
            jpgCounter += 1;   
        } 
        else {
            //Continue writing 512 blocks to the current output file
            if (outptr != NULL){
                fwrite(buffer, 512, 1, outptr);
            }
        }
    }
    //Close both files at the end
    fclose(outptr); 
    fclose(inptr); 
    return 0;
}

bool isJpg(BYTE bytes1[], BYTE bytes2[]){
    for (int i = 0; i < 4; i++){
        if (bytes1[i] != bytes2[i]){
            return false;
        }
    }
    return true;
}
