/**
File: output.c
Author: Blake Ackland
Description: 
*/
#include <stdio.h>
#include "struct.h"

int file_write()
{
    FILE *out = fopen("myDoggo.pgm", "w")

    if (out == NULL)
    {
        fputs("error opening file\n", stderr);
        exit(1);
    }

    fwrite(arraySize, sizeof(unsigned char), imagesize, out);
    fclose(out);
    return 0;
}