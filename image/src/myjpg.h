#include <stdio.h>
#include <stdlib.h>

#include "jpeglib.h"

typedef struct{
  unsigned char *data;
  unsigned int width;
  unsigned int height;
  unsigned int ch;
} RAWDATA_t;

int jpegFileReadDecode(RAWDATA_t *, const char*);
int jpegFileEncodeWrite(RAWDATA_t *, const char*);
int freeRawData(RAWDATA_t *);
RAWDATA_t imgToGrayScale(RAWDATA_t *);