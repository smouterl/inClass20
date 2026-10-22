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



Image_data get_header(char *file_name, FILE *fp){
    char line[500];
    Image_data image = {0};

    for(int i = 0; i < 4; i++){
        fgets(line, 500, fp);
        printf("%s\n", line);
        
    }


    fread(image.image, sizeof(unsigned char), image.image_width * image.image_height, fp);


    return image;
}


void main(void){
    FILE *fp = fopen("tank.pgm", "r");
        if(!fp){
        fputs("ERROR opening file\n", stderr);
        exit(1);
    }
    get_header("tank.pgm", fp);
}
