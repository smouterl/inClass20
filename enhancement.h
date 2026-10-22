/**********************************************
* Filename: enhancement.h
* Description: Image enhancement
* Author: Nick G
* Date: 10/15/26
***********************************************/

void enhance(int height, int width, const uint8_t src[height][width], uint8_t dst[height][width], const uint8_t LPFArray[height][width]);