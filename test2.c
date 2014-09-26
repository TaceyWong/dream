//反色效果

for(int i=1;i<height;i++)
{
    for(int j=1;j<width;j++)
    {
        output_r[i][j]=255 - r[i][j] ;
        output_g[i][j]=255 - g[i][j] ;
        output_b[i][j]=255 - b[i][j] ;
    }
}
