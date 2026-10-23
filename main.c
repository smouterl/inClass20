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
#include <string.h>
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
    image.width = atoi(strtok(line, " "));
    image.height = atoi(strtok(NULL, " "));
    fgets(line, 500, fp);
    image.pixel_depth = atoi(line);

    image.image = (unsigned char *)malloc(image.width * image.height * sizeof(unsigned char));
    fread(image.image, sizeof(unsigned char), image.width * image.height, fp);


    return image;
}


int main(void){
    FILE *fp = fopen("tank.pgm", "r");
        if(!fp){
        fputs("ERROR opening file\n", stderr);
        exit(1);
    }
    Image_data image = get_header("tank.pgm", fp);


    // Allocate array of char pointers
    unsigned char **LPFArray = (unsigned char **)malloc(image.height * sizeof(unsigned char *));

    // Allocate memory for each row
    for (int i = 0; i < image.height; i++) {
        LPFArray[i] = (unsigned char *)malloc(image.width * sizeof(unsigned char));
    }

    
    // Allocate array of char pointers
    unsigned char **enhancedArray = (unsigned char **)malloc(image.height * sizeof(unsigned char *));

    // Allocate memory for each row
    for (int i = 0; i < image.height; i++) {
        enhancedArray[i] = (unsigned char *)malloc(image.width * sizeof(unsigned char));
    }
    
    boxcar_filter(image.height, image.width, image.image, LPFArray);
    enhance(image.height, image.width, image.image, enhancedArray, LPFArray);
    
    FILE *LPFout = fopen("LPF.pgm", "w");
    file_write(LPFArray, "LPF.pgm", LPFout, image.width, image.height);
    fclose(LPFout);

    FILE *enhancedOut = fopen("enhanced.pgm", "w");
    file_write(enhancedArray, "enhanced.pgm", enhancedOut, image.width, image.height);
    fclose(enhancedOut);
    fclose(fp);
    return 0;
}
