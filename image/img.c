#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE  *fpi, *fpo;
  unsigned char  idat;
  /* 引数のチェック */
  if (argc != 3) {
    fprintf(stderr, "Usage: %s [input] [output]\n", argv[0]);
    exit(1);
  }

  /* 入力画像のオープン */
  if((fpi=fopen(argv[1], "rb")) == NULL){
    fprintf(stderr, "input file open error\n");
    exit(1);
  }
  /* 出力画像のオープン */
  if((fpo=fopen(argv[2], "wb")) == NULL){
    fprintf(stderr, "output file open error\n");
    exit(1);
  }
  /* 入力画像の読込み */
  while (fread(&idat, sizeof(unsigned char), 1, fpi) == 1){
    /* 2倍の変換 */
    if (idat * 2 > 255) {
      idat = 255;
    } else {
      idat = idat * 2;
    } 
    printf("%d\n",idat);
    /* 変換データの書出し */
    if(fwrite(&idat, sizeof(unsigned char), 1, fpo) != 1){
      fprintf(stderr, "data write error\n");
      exit(1);
    }
  }
  fclose(fpi);
  fclose(fpo);
  return (0);
}