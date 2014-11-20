1、实现雾化效果的方法，让一个像素点的RGB等于周围随机的一个像素点的RGB值

2、实现马赛克效果的方法，让一定区域的像素块全部像素点的RGB等于该像素块内某一像素点的RGB
int R = 100;
int point_x = width/2;
int point_y = height/2;
//int sx,sy;
for(i=1;i<height-11;i++)
    for(j=1;j<width-11;j++)
		{

                    if((i- point_y)*(i-point_y)+(j- point_x)*(j-point_x)<R*R)
                    {
                        //sx = (int)(rand()%20-10);
                        //sy = (int)(rand()%20-10);

                        if(i<point_y)
                        if(j<point_x)
                        {
                            output_r[i][j]=r[point_y-R+((R-point_y+i)/10)*10][point_x-R+((R-point_x+j)/10)*10];
                            output_g[i][j]=g[point_y-R+((R-point_y+i)/10)*10][point_x-R+((R-point_x+j)/10)*10];
                            output_b[i][j]=b[point_y-R+((R-point_y+i)/10)*10][point_x-R+((R-point_x+j)/10)*10];
                        }
                        else
                            {
                            output_r[i][j]=r[point_y-R+((R-point_y+i)/10)*10][point_x+((j-point_x)/10)*10];
                            output_g[i][j]=g[point_y-R+((R-point_y+i)/10)*10][point_x+((j-point_x)/10)*10];
                            output_b[i][j]=b[point_y-R+((R-point_y+i)/10)*10][point_x+((j-point_x)/10)*10];
                        }
                        else
                            if(j<point_x)
                            {
                            output_r[i][j]=r[point_y+((i-point_y)/10)*10][point_x-R+((R-point_x+j)/10)*10];
                            output_g[i][j]=g[point_y+((i-point_y)/10)*10][point_x-R+((R-point_x+j)/10)*10];
                            output_b[i][j]=b[point_y+((i-point_y)/10)*10][point_x-R+((R-point_x+j)/10)*10];
                        }
                        else{
                            output_r[i][j]=r[point_y-R+((R-point_y+i)/10)*10][point_x+((j-point_x)/10)*10];
                            output_g[i][j]=r[point_y-R+((R-point_y+i)/10)*10][point_x+((j-point_x)/10)*10];
                            output_b[i][j]=r[point_y-R+((R-point_y+i)/10)*10][point_x+((j-point_x)/10)*10];
                        }

                     }
		}

