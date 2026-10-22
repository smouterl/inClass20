/**********************************************
* Filename: enhancement.c
* Description: Image enhancement
* Author: Nick G
* Date: 10/15/26
***********************************************/

void enhance(unsigned char LPFArray[256][256], unsigned char originalArray[256][256], unsigned char enhancedArray[256][256]) {
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {

            int value = 4 * originalArray[i][j] - 3 * LPFArray[i][j];

            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            enhancedArray[i][j] = value;
        }
    }
}
  
    