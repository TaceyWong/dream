int temp = 0;
for(i=1;i<height-1;i++)
    for(j=1;j<width-1;j++)
    {
        temp = (int)(0.7 * r[i][j]) + (int)(0.2 * g[i][j]) + (int)(0.1 * b[i][j]);

        output_r[i][j]=temp;
        output_g[i][j]=temp;
        output_b[i][j]=temp;
    }

for(i=1;i<height-1;i++)
    for(j=1;j<width-1;j++)
    {
        if (abs(output_r[i][j]-output_r[i+1][j+1]) >= 25 )
            output_r[i][j]=output_g[i][j]=output_b[i][j]=0;
        else
            output_r[i][j]=output_g[i][j]=output_b[i][j]=255;
    }
