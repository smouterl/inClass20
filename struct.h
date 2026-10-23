#ifndef STRUCT
#define STRUCT


typedef struct {
    char *PJM_format;
    char *creator;
    unsigned int width;
    unsigned int height;
    unsigned int pixel_depth;
    unsigned char **image;
} Image_data;

#endif