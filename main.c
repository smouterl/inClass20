/********************************************************************
* @file assignment.c
* @brief A simple state machine
* @param int argc - the number of arguments
* @param char* argv[] string of args
* @return - the int return code
* @author Davis Knowles
* @date 10/05/2026
* @version 1.0
* @copyright Copyright (C) 2026 C&E Solutions SP. All Rights Reserved.
*Compile:
* gcc calc.c circle.c -o calc
*Run:
* ./calc
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "enhancement.h"
#include "LPF.h"
#include "output.h"


Image_data get_header(char *file_name, FILE *fp){
    char line[500];
    Image_data image = {0};

    fgets(line, 500, fp);
    image.PJM_format = line;
    fgets(line, 500, fp);
    image.creator = line;
    fgets(line, 500, fp);
    image.image_width = atoi(strtok(line, " "));
    image.image_height = atoi(strtok(NULL, " "));
    fgets(line, 500, fp);
    image.pixel_depth = atoi(line);

    fread(image.image, sizeof(unsigned char), image.image_width * image.image_height, fp);


    return image;
}


void main(void){
    FILE *fp = fopen("tank.pgm", "r");
        if(!fp){
        fputs("ERROR opening file\n", stderr);
        exit(1);
    }
    Image_data image = get_header("tank.pgm", fp);

    unsigned char *LPFArray[image.height][image.width];
    unsigned char *enhancedArray[image.height][image.width];
    boxcar_filter_2d_float(image.height, image.width, image.image, LPFArray);
    enhance(image.height, image.width, image.image, enhancedArray, LPFArray);
    
    FILE *LPFout = fopen("LPF.pgm", "w");
    file_write(LPFArray, "LPF.pgm", LPFout);
    fclose(LPFout);

    FILE *enhancedOut = fopen("enhanced.pgm", "w");
    file_write(enhancedArray, "enhanced.pgm", enhancedOut);
    fclose(enhancedOut);
    fclose(fp);
}
