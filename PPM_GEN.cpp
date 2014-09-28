#include <iostream>
#include <cmath>
#include <cstdlib>
#define DIM 1024
#define DM1 (DIM-1)
#define _sq(x) ((x)*(x))     //平方
#define _cb(x) abs((x)*(x)*(x)) //立方绝对值
#define _cr(x) (unsigned char)(pow((x),1.0/3.0)) //开立方

unsigned char GR(int,int);
unsigned char BL(int ,int);

unsigned char RD(int i,int j)
{
	//返回 （i，j）坐标像素点的Red值
}
unsigned char GR(int i,int j)
{
	
	//返回 （i，j）坐标像素点的Green值
}

unsigned char BL(int i,int j)
{
	//返回 （i，j）坐标像素点的Blue值

}

void pixel_write(int ,int );
FILE *fp = NULL;   //声明全局文件指针

int main()
{
	fp = fopen("mathpic.ppm","wb");  //打开文件
	fprintf(fp,"P6\n%d %d\n255\n",DIM,DIM);//PPM文件头 
	/*
	*第一行P6
	*第二行宽度
	*第三行高度
	*/
	for(int j = 0;j<DIM;j++ )
		for(int i = 0;i<DIM;i++)
		  pixel_write(i,j);
	fclose(fp);
	return 0;
}


//写入一个像素点的RGB值
void pixel_write(int i,int j)
{
	static unsigned char color[3];
	color[0] = RD(i,j)&255; //&255(11111111)保证是一个字节
	color[1] = GR(i,j)&255;
	color[2] = BL(i,j)&255;
	fwrite(color,1,3,fp);
	/*
	  size_t fwrite(const void* buffer,size_t size ,size_t count,FILE *stream)
	  buffer 获取数据的地址
	  size   写入内容的单字节数
	  count  要进行写入size字节的数据项个数
	  stream 目标文件指针
	  返回：实写入数据项个数count
	*/
	
}












