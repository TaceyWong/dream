/***********************************************
int model[]={1, 2, 1, 2, 4, 2, 1, 2, 1};//高斯模板
//int model[]=-{1, -1, -1, -1, 9, -1, -1, -1, -1};//  拉普拉斯模板
for(i=1;i<height-1;i++)
    for(j=1;j<width-1;j++)
    {
    //int temp[3] ={0,0,0} ;
    //output_r[i][j]=0;
    //output_g[i][j]=0;
    //output_b[i][j]=0;
    int index = 0;
    int x=-1,y=-1;
    for(;x<1;x++)
        for(;y<1;y++)
        {
            output_r[i][j]+=r[i+x][j+y]*model[index];
            output_g[i][j]+=g[i+x][j+x]*model[index];
            output_b[i][j]+=b[i+x][j+x]*model[index];
            index ++;
        }
    output_r[i][j]=output_r[i][j]>255? 255: output_r[i][j];
    output_g[i][j]=output_g[i][j]>255? 255: output_g[i][j];
    output_b[i][j]=output_b[i][j]>255? 255: output_b[i][j];

    }
************************************************************/
