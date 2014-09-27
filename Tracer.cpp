#include<stdlib.h>// card > aek.ppm
#include<stdio.h>
#include<math.h>

typedef int i ;
typedef float f ;

//定义向量结构体，重载运算符 
struct vector 
{
    f x,y,z ;                          //x,y,z方向的值 
    vector operator+(vector r)		   //重载加号运算符（三个方向各自相加） 
    {
        return vector(x+r.x,y+r.y,z+r.z);
    }
    vector operator*(f r)			   //重载乘号运算符 （） 
    {
        return vector(x*r,y*r,z*r);
    }
    f operator%(vector r)				//重载取余运算符（三个方向各自相乘） 
    {
        return x*r.x+y*r.y+z*r.z ;
    }
    vector()							//无参构造 
    {
    }
    vector operator^(vector r)			//重载幂次方运算符（） 
    {
        return vector(y*r.z-z*r.y,z*r.x-x*r.z,x*r.y-y*r.x);
    }
    vector(f a,f b,f c)					//三参构造函数 
    {
        x=a ;
        y=b ;
        z=c ;
    }
    vector operator!()					//重载！（自身的各个方向想乘开方的倒数再乘以自身） 
    {
        return *this * (1/sqrt(*this % *this));
    }
};


//转换成二进制，相当于字模 
i G[]={
       262143,
	   512,
	   512,
	   512,
	   131070,
	   512,
	   512,
	   512,
	   65532 
		};


//返回一个浮点型随机数 
f R()
{
    return(f)rand()/RAND_MAX ;
}

//
i T(vector o,vector d,f&t,vector&n)
{
    t=1e9 ;
    i m=0 ;
    f p=-o.z/d.z ;
    if(.01<p)t=p,n=vector(0,0,1),m=1 ;
    for(i k=19;k--;)for(i j=9;j--;)if(G[j]&1<<k)
    {
        vector p=o+vector(-k,0,-j-4);
        f b=p%d,c=p%p-1,q=b*b-c ;
        if(q>0)
        {
            f s=-b-sqrt(q);
            if(s<t&&s>.01)t=s,n=!(p+d*t),m=2 ;
        }
    }
    return m ;
}

vector S(vector o,vector d)
{
    f t ;
    vector n ;
    i m=T(o,d,t,n);
    if(!m)return vector(.7,.6,1)*pow(1-d.z,4);
    vector h=o+d*t,l=!(vector(9+R(),9+R(),16)+h*-1),r=d+n*(n%d*-2);
    f b=l%n ;
    if(b<0||T(h,l,t,n))b=0 ;
    f p=pow(l%r*(b>0),99);
    if(m&1)
    {
        h=h*.2 ;
        return((i)(ceil(h.x)+ceil(h.y))&1?vector(3,1,1):vector(3,3,3))*(b*.2+.1);
    }//ceil(a)不小于a的最小整数;floor(a)不大于a的最大整数 
    return vector(p,p,p)+S(h,r)*.5 ;
}


//主函数 
i main()
{
    printf("P6 512 512 255 "); //PPM格式文件头 
    vector g=!vector(-6,-16,0),a=!(vector(0,0,1)^g)*.002,b=!(g^a)*.002,c=(a+b)*-256+g ;
    for(i y=512;y--;)
	for(i x=512;x--;)
    {
        vector p(13,13,13);
        for(i r=64;r--;)
        {
            vector t=a*(R()-.5)*99+b*(R()-.5)*99 ;
            p=S(vector(17,16,8)+t,!(t*-1+(a*(R()+x)+b*(y+R())+c)*16))*3.5+p ;
        }
        printf("%c%c%c",(i)p.x,(i)p.y,(i)p.z);
    }
}
