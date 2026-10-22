/**********************************************
* Filename: ICA20.c
* Description: Image processing
* Author: Nick G
* Date: 10/15/26
***********************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *input_file, *output_file;
    char inPutarray[256][256];
    input_file = fopen("doggo.pgm", "r");
 
    for(int i = 0; i < 256; i++)
    {
        for(int j = 0; j < 256; j++)
        {
            fscanf(input_file, "%c", &inPutarray[i][j]);
        }
    }


    
    
}
