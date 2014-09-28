
//第一个（完全用static变量进行控制）

unsigned char RD(int i,int j)
{
	static double k;
	k+=rand()/1./RAND_MAX;
	int l=k;
	l%=512;
	return l>255?511-l:l;
}
 
unsigned char GR(int i,int j)
{
	static double k;
	k+=rand()/1./RAND_MAX;
	int l=k;
	l%=512;
	return l>255?511-l:l;
}
 
unsigned char BL(int i,int j)
{
	static double k;
	k+=rand()/1./RAND_MAX;
	int l=k;
	l%=512;
	return l>255?511-l:l;
}

//第二个（三角函数弄得我头晕）
unsigned char RD(int i,int j)
{
  return (char)(_sq(cos(atan2(j-512,i-512)/2))*255);
}
 
unsigned char GR(int i,int j)
{
  return (char)(_sq(cos(atan2(j-512,i-512)/2-2*acos(-1)/3))*255);
}
 
unsigned char BL(int i,int j)
{
  return (char)(_sq(cos(atan2(j-512,i-512)/2+2*acos(-1)/3))*255);
  
}

//嘿嘿，我自己的
unsigned char RD(int i,int j)
{
  return (i)%256;
}

unsigned char GR(int i,int j)
{
  return (j)/4%256;
}

unsigned char BL(int i,int j)
{
  return (i+j)/4%256;
}

//第三个 棋盘
unsigned char RD(int i,int j)
{
  return BL(i,j)*2;
  #define t(m,n)_sq(m)+_sq(n)
  #define z(m,n)t(m*32-i,n*32-j)
  #define q(m,n,k)if(z(m,n)<196)return k*255;if(z(m,n)<225)return 0;
}

unsigned char GR(int i,int j)
{
  BL(i,j);
}

unsigned char BL(int i,int j)
{
  q(16,16,1)q(15,16,0)q(16,15,0)q(17,16,0)q(16,17,0)
  return(i&31)&&(j&31)?80:0;
}

//分形几何
unsigned char RD(int i,int j)
{
	float x=0,y=0;
	int k;
	for(k=0;k++<256;)
	{
		float a=x*x-y*y+(i-768.0)/512;
		y=2*x*y+(j-512.0)/512;
		x=a;
		if(x*x+y*y>4)
			break;
	}
	return log(k)*47;
}
 
unsigned char GR(int i,int j)
{
	float x=0,y=0;
	int k;
	for(k=0;k++<256;)
	{
		float a=x*x-y*y+(i-768.0)/512;
		y=2*x*y+(j-512.0)/512;
		x=a;
		if(x*x+y*y>4)break;
	}
	return log(k)*47;
}
 
unsigned char BL(int i,int j)
{
	float x=0,y=0;
	int k;
	for(k=0;k++<256;)
	{
		float a=x*x-y*y+(i-768.0)/512;
		y=2*x*y+(j-512.0)/512;
		x=a;
		if(x*x+y*y>4)break;
	}
	return 128-log(k)*23;
}

//放大镜效果
unsigned short RD(int i,int j){
#define F(x) float x
#define R return
#define Ci (DIM/2)
#define Cj Ci
#define Z (Ci/2)
#define G (Ci/8)
#define N 3
R BL(i,j);
}

unsigned short GR(int i,int j){
#define Y(x) sqrt(1.-_sq(x))
R BL(i,j);
}

unsigned short BL(int i,int j){
F(r)=sqrt(0.+_sq(i-Ci)+_sq(j-Cj));F(s)=r/Z;if(s<1){i-=Ci;j-=Cj;F(k)=(Y(s)*Y(s/N)+_sq(s)/N)*N;i=i/k+Ci;j=j/k+Cj;}R (i/G+j/G)%2*255;
}

//油画效果
unsigned char RD(int i,int j){
#define r(n)(rand()%n)
static char c[1024][1024];return!c[i][j]?c[i][j]=!r(999)?r(256):RD((i+r(2))%1024,(j+r(2))%1024):c[i][j];
}
 
unsigned char GR(int i,int j){
static char c[1024][1024];return!c[i][j]?c[i][j]=!r(999)?r(256):GR((i+r(2))%1024,(j+r(2))%1024):c[i][j];
}
 
unsigned char BL(int i,int j){
static char c[1024][1024];return!c[i][j]?c[i][j]=!r(999)?r(256):BL((i+r(2))%1024,(j+r(2))%1024):c[i][j];
}

//波浪效果
unsigned char RD(int i,int j){
float s=3./(j+99);
float y=(j+sin((i*i+_sq(j-700)*5)/100./DIM)*35)*s;
return (int((i+DIM)*s+y)%2+int((DIM*2-i)*s+y)%2)*127;
}
 
unsigned char GR(int i,int j){
float s=3./(j+99);
float y=(j+sin((i*i+_sq(j-700)*5)/100./DIM)*35)*s;
return (int(5*((i+DIM)*s+y))%2+int(5*((DIM*2-i)*s+y))%2)*127;
}
 
unsigned char BL(int i,int j){
float s=3./(j+99);
float y=(j+sin((i*i+_sq(j-700)*5)/100./DIM)*35)*s;
return (int(29*((i+DIM)*s+y))%2+int(29*((DIM*2-i)*s+y))%2)*127;
}

