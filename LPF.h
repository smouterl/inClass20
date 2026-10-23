#ifndef LPF_H
#define LPF_H

/* Apply a 5x5 boxcar filter; copy the two-pixel border from src to dst. */
void boxcar_filter(int height, int width,
                           unsigned char *src,
                           unsigned char *dst);

#endif
