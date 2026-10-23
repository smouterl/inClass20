/**********************************************
* Filename: enhancement.c
* Description: Image enhancement
* Author: Nick G
* Date: 10/15/26
***********************************************/

#include <stdint.h>
#include <stdlib.h>

void enhance(int height, int width, const char *src, char *dst, const char *LPFArray) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            int value = 4 * atoi(src[i * width + j]) - 3 * atoi(LPFArray[i * width + j]);

            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            dst[i * width + j] = value;
        }
    }
}
  
    