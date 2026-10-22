/**
File: output.c
Author: Blake Ackland
Description: Takes an array of unsigned chars and creates new file
             to write in values
*/
#include <stdio.h>
#include "output.h"
#include "struct.h"

<<<<<<< HEAD
int file_write(unsigned char *array, char *file_name, FILE *out)
=======
int file_write(unsigned char *array)
>>>>>>> 0ed6dcd (Add output header)
{
    *out = fopen(file_name, "w");

    if (out == NULL)
    {
        fputs("error opening file\n", stderr);
        exit(1);
    }

    fwrite(sizeof(array), sizeof(unsigned char), 515 * 388, out);
    fclose(out);
    return 0;
}
