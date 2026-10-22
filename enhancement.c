/**********************************************
* Filename: enhancement.c
* Description: Image enhancement
* Author: Nick G
* Date: 10/15/26
***********************************************/

void enhance(int height, int width, const uint8_t src[height][width], uint8_t dst[height][width], const uint8_t LPFArray[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            int value = 4 * src[i][j] - 3 * LPFArray[i][j];

            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            dst[i][j] = value;
        }
    }
}
  
    