/***********************************************中值黑白
for(i=1;i<height-1;i++)
    for(j=1;j<width-1;j++)
    {
        int temp = (r[i][j]+g[i][j]+b[i][j])/3;

        output_r[i][j]=temp;
        output_g[i][j]=temp;
        output_b[i][j]=temp;
    }
********************************************************/

/*************************************************最大值黑白
for(i=1;i<height-1;i++)
    for(j=1;j<width-1;j++)
    {
        int temp = r[i][j]>g[i][j]?(r[i][j]>b[i][j]?r[i][j]:b[i][j]):(g[i][j]>b[i][j]?g[i][j]:b[i][j]);

        output_r[i][j]=temp;
        output_g[i][j]=temp;
        output_b[i][j]=temp;
    }
************************************************************/
/****************************************************加权黑白
for(i=1;i<height-1;i++)
    for(j=1;j<width-1;j++)
    {
        int temp = (int)(0.7 * r[i][j]) + (int)(0.2 * g[i][j]) + (int)(0.1 * b[i][j]);

        output_r[i][j]=temp;
        output_g[i][j]=temp;
        output_b[i][j]=temp;
    }
**************************************************************/
