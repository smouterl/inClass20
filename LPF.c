/**********************************************
* Filename: LPF.c
* Description: Low Pass Filter Logic
* Author: Logan Smouter
* Date: 10/22/2026
***********************************************/
#include <stdint.h>
#include <math.h> // Required for the roundf() function

void boxcar_filter_2d_float(int height, int width, const uint8_t src[height][width], uint8_t dst[height][width]) {
    
    for (int y = 2; y < height - 2; y++) {
        for (int x = 2; x < width - 2; x++) {
            
            uint32_t sum = 0;

            for (int ky = -2; ky <= 2; ky++) {
                for (int kx = -2; kx <= 2; kx++) {
                    sum += src[y + ky][x + kx];
                }
            }

            //(float)sum converts the integer to a float
            dst[y][x] = (uint8_t)roundf((float)sum / 25.0f);
        }
    }
}
