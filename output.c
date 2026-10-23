/**
File: output.c
Author: Blake Ackland
Description: Takes an array of unsigned chars and creates new file
             to write in values
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "output.h"
#include "struct.h"


int file_write(unsigned char **array, char *file_name, FILE *out, int width, int height)
{
    out = fopen(file_name, "wb");

    if (out == NULL)
    {
        fputs("error opening file\n", stderr);
        exit(1);
    }


    fprintf(out, "P5\n%d %d\n255\n", width, height);
    for (int y = 0; y < height; y++) {
        fwrite(array[y], sizeof(unsigned char), width, out);
    }
    fclose(out);
    return 0;
}
