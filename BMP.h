/*

(bitmap-file header)	BITMAPFILEHEADER	bmfh	14 
(bitmap-information header)	BITMAPINFOHEADER	bmih	40 
(color table)	RGBQUAD	aColors[]	4N ——>非必须，24位不需要 
 Data	BYTE	aBitmapBits[]	x  
*/


#include <time.h>
#include <math.h>


#define BITMAPFILEHEADERLENGTH 14   // BMP文件头是14 
#define BM 19778                    // BM对应的ASSI编码 


/* 测试文件是否为BMP格式*/
int bmpFileTest(FILE* fpbmp,FILE* fpout);

/* To get the OffSet of header to data part */
void bmpHeaderPartLength(FILE* fpbmp);

/* 获得BMP图片的宽度和高度 */
void BmpWidthHeight(FILE* fpbmp);

//获得图片的Data（RGB值） 
void getDataPart(FILE* fpbmp);

// output data to corresponding txt file 
void bmpoutput(FILE *fpout);



unsigned int OffSet = 0;    // 信息头（从文件头道像素数据）OffSet from Header part to Data Part
long width ;          // 数据部分的宽度 
long height ;         // 数据部分的高度 

//保存图片像素信息RGB值的数组（原图、处理后的图片） 
static unsigned char r[2000][2000],output_r[2000][2000];
static unsigned char g[2000][2000],output_g[2000][2000];
static unsigned char b[2000][2000],output_b[2000][2000];


void bmpoutput(FILE* fpout)
{
         int i, j=0;
         int stride;
         unsigned char* pixout=NULL;

         stride=(24*width+31)/8;
         stride=stride/4*4;
         pixout=(unsigned char *)malloc(stride);
/*
不知道为什么不能放在这里
        unsigned char *fp_temp;
	      fseek(fpbmp, 0L, SEEK_SET);
	      fseek(fpout, 0L, SEEK_SET);

	      fp_temp=(unsigned char *)malloc(OffSet);
        fread(fp_temp, 1, OffSet, fpbmp);
        fwrite(fp_temp,1,OffSet,fpout);
*/

         fseek(fpout, OffSet, SEEK_SET);


         for(j=0;j<height;j++)
         {
            for(i=0;i<width;i++)
            {
                pixout[i*3+2]=output_r[height-1-j][i];
                pixout[i*3+1]=output_g[height-1-j][i];
                pixout[i*3]  =output_b[height-1-j][i];
            }
            fwrite(pixout, 1, stride, fpout);
          }

}
void getDataPart(FILE* fpbmp)
{
         int i, j=0;
         int stride;
         unsigned char* pix=NULL;

         fseek(fpbmp, OffSet, SEEK_SET);
         stride=(24*width+31)/8;
         stride=stride/4*4;
         pix=(unsigned char *)malloc(stride);

         for(j=0;j<height;j++)
         {
             fread(pix, 1, stride, fpbmp);
             for(i=0;i<width;i++)
             {
                 r[height-1-j][i]   =pix[i*3+2];
                 g[height-1-j][i]   =pix[i*3+1];
                 b[height-1-j][i]   =pix[i*3];

			           //如果不对图片进行相关处理，将输出一个和原图像一样的图片 
                 output_r[height-1-j][i]   =pix[i*3+2];
                 output_g[height-1-j][i]   =pix[i*3+1];
                 output_b[height-1-j][i]   =pix[i*3];
            }
         }
}


int bmpFileTest(FILE* fpbmp,FILE* fpout)
{
     unsigned short bfType = 0;

     if (fpbmp == NULL)
     {
        printf("Open bmp failed!!!\n");
        return 1;
     }

     if (fpout == NULL)
     {
        printf("Open out.bmp failed!!!\n");
        return 1;
     }

     fseek(fpbmp, 0L, SEEK_SET);//seek_set ????
     fread(&bfType, sizeof(char), 2, fpbmp);
     if (BM != bfType)
     {
 		     printf("文件不是BMP文件.!!!\n");
 		     exit(1);
     }
     return 0;
}



void bmpHeaderPartLength(FILE* fpbmp)
{
     fseek(fpbmp, 10L, SEEK_SET);
     fread(&OffSet, sizeof(char), 4, fpbmp);
     printf("The Header Part is of length %d.\n", OffSet);
}


/* 获得BMP图片的宽度和高度 */
void BmpWidthHeight(FILE* fpbmp)
{
     fseek(fpbmp, 18L, SEEK_SET); //将指针移到距离文件开始18字节处 
     fread(&width, sizeof(char), 4, fpbmp); //将4Xsizeof(char)的数据从*fpbmp读取到到width 
     fseek(fpbmp, 22L, SEEK_SET);
     fread(&height, sizeof(char), 4, fpbmp);
     printf("The Width of the bmp file is %ld.\n", width);
     printf("The Height of the bmp file is %ld.\n", height);
}
