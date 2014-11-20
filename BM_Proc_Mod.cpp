#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bmp.h"

int main(int argc, char* argv[])
{

    //打开文件;
    FILE *fpbmp =NULL ;
    FILE *fpout = NULL;
    fpbmp= fopen("1.bmp", "rb");
    fpout= fopen("out.bmp", "wb+");
    bmpFileTest(fpbmp,fpout);        //测试打开的文件时否为BMP文件 
    bmpHeaderPartLength(fpbmp);      //
    BmpWidthHeight(fpbmp);           //
    unsigned char *fp_temp;
    


	  fseek(fpbmp, 0L, SEEK_SET);
	  fseek(fpout, 0L, SEEK_SET);

	  fp_temp=(unsigned char *)malloc(OffSet);
    fread(fp_temp, 1, OffSet, fpbmp);
    fwrite(fp_temp,1,OffSet,fpout);
    getDataPart(fpbmp);              

  /*
	      图像处理代码 
  */



    bmpoutput(fpout);
    fclose(fpbmp);
    fclose(fpout);
    return 0;
}
