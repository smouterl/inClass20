/**
File: output.c
Author: Blake Ackland
Description: 
*/
#include <stdio.h>
#include "struct.h"

int file_write(array)
{
    FILE *out = fopen("myDoggo.pgm", "w")

    if (out == NULL)
    {
        fputs("error opening file\n", stderr);
        exit(1);
    }

    fwrite(sizeof(array), sizeof(unsigned char), 515 * 388, out);
    fclose(out);
    return 0;
}