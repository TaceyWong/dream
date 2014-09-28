int cen_x = width/2;
	int cen_y = height/2;
    int R =  cen_x<cen_y?cen_x:cen_y;
    int distance = 0;
	for(i=1;i<height-1;i++)
    for(j=1;j<width-1;j++)
		{


                distance = (int)pow((j-cen_x)*(j-cen_x)+(i-cen_y)*(i-cen_y),0.5);
                if(distance <= R)
                {
                    int x = (int)(distance*(j-cen_x)/R+cen_x);
                    int y = (int)(distance*(i-cen_y)/R+cen_y);
                    //凸透镜
                    output_r[y][x]=r[i][j];
                    output_g[y][x]=g[i][j];
                    output_b[y][x]=b[i][j];
                    //凹透镜
                    output_r[i][j]=r[y][x];
                    output_g[j][j]=g[y][x];
                    output_b[i][j]=b[y][x];
                    

                }
		}
