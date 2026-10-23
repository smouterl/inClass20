/**********************************************
* Filename: LPF.c
* Description: Low Pass Filter Logic
* Author: Logan Smouter
* Date: 10/22/2026
***********************************************/
#include "LPF.h"
#include <math.h> // Required for the roundf() function

void boxcar_filter(int height, int width, unsigned char **src, unsigned char **dst) {
    /* Preserve the border */
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            dst[y * width + x] = src[y * width + x];
        }
    }

    for (int y = 2; y < height - 2; y++) {
        for (int x = 2; x < width - 2; x++) {
            
            unsigned int sum = 0;

            for (int ky = -2; ky <= 2; ky++) {
                for (int kx = -2; kx <= 2; kx++) {
                    sum += src[(y + ky) * width + (x + kx)];
                }
            }

            //(float)sum converts the integer to a float
            dst[y * width + x] = (unsigned char)roundf((float)sum / 25.0f);
        }
    }
}
