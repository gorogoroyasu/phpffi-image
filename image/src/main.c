#include "myjpg.h"

int main(int argc, char *argv[]){

  RAWDATA_t raw;
  int i, j, c;
  int ave, sum;
  char outname[256];

  FILE *fo;

  if(argc != 2){
    printf("ファイル名が指定されていません\n");
    return -1;
  }

  if(jpegFileReadDecode(&raw, argv[1]) == -1){
    printf("tiffFileReadDecode error\n");
    return -1;
  }

  printf("raw->data = %p\n", raw.data);
  printf("raw->width = %d\n", raw.width);
  printf("raw->height = %d\n", raw.height);
  printf("raw->ch = %d\n", raw.ch);

// #if 0
  /* ちゃんと読み込めているか確認する場合はここを有効に */
//   fo = fopen("testoutput.ppm", "wb");
//   fprintf(fo, "P6\n#\n%d %d\n255\n", raw.width, raw.height);
//   fwrite(raw.data, raw.height * raw.width * 3, 1,fo);
//   fclose(fo);
// #endif

  /* グレースケールに変換 */
//   for(j = 0; j < raw.height; j++){
//     for(i = 0; i < raw.width; i++){
//       sum = 0;
//       for(c = 0; c < raw.ch; c++){
//         sum += raw.data[raw.ch * (i + j * raw.width) + c];
//       }
//       ave = sum / raw.ch;
//       for(c = 0; c < raw.ch; c++){
//         raw.data[raw.ch * (i + j * raw.width) + c] = ave;
//       }
//     }
//   }
  raw = imgToGrayScale(&raw);
  sprintf(outname, "%s", "output.jpg");

  if(jpegFileEncodeWrite(&raw, outname) == -1){
    printf("jpegFileEncodeWrite error\n");
    freeRawData(&raw);
    return -1;
  }

  freeRawData(&raw);

  return 0;
}