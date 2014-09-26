//浮雕
for(int i=1;i<height;i++)
{
    for(int j=1;j<width;j++)
    {
        output_r[i][j]=r[i-1][j-1]-r[i+1][j+1]+128 ;
        output_g[i][j]=g[i-1][j-1]-g[i+1][j+1]+128 ;
        output_b[i][j]=b[i-1][j-1]-b[i+1][j+1]+128 ;
    }
}
