/**********************************************
* Filename: enhancement.h
* Description: Image enhancement
* Author: Nick G
* Date: 10/15/26
***********************************************/
#include <stdint.h>

void enhance(int height, int width, const uint8_t *src, uint8_t *dst, const uint8_t *LPFArray);