int i,j;			 
	for(i=1;i<height-1;i++)
    for(j=1;j<width-1;j++)
    {
    
    output_b[i][j]=+50;
    output_g[i][j]=output_g[i][j]*0.85+30;
    output_b[i][j]=output_b[i][j]*0.75+20;
	output_r[i][j]=output_r[i][j]>255? 255: output_r[i][j];
    output_g[i][j]=output_g[i][j]>255? 255: output_g[i][j];
    output_b[i][j]=output_b[i][j]>255? 255: output_b[i][j];
    output_r[i][j]=output_r[i][j]<0? 0: output_r[i][j];
    output_g[i][j]=output_g[i][j]<0? 0: output_g[i][j];
    output_b[i][j]=output_b[i][j]<0? 0: output_b[i][j];
    

    }
