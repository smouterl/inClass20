#ifndef LPF_H
#define LPF_H

#include <stdint.h>

/* Apply a 5x5 boxcar filter; the two-pixel border is left unchanged in dst. */
void boxcar_filter(int height, int width,
                           const uint8_t src[height][width],
                           uint8_t dst[height][width]);

#endif
