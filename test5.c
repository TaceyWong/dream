for(i=1;i<height-1;i++)
    for(j=1;j<width-1;j++)
    {

        int block = rand()%RAND_MAX;
        //像素块大小
            int x = i + block % 29;//19可以调节
            int y = j + block % 29;//19可以调节
        if (x >= height)
            x = height - 1;
        if (y >= width)
            y = width - 1;
        output_r[i][j]=r[x][y];
        output_g[i][j]=g[x][y];
        output_b[i][j]=b[x][y];

    }
