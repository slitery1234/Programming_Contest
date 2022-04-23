#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x[24],y[60];
    float z[1440];
    for(int i=0;i<24;i++)
    {
        x[i]=i*30;
    }
    for(int i=0;i<60;i++)
    {
        y[i]=i*6;
    }

    for(int i=0;i<12;i++)
    {
        for(int j=0;j<60;j++)
        {
            if(y[j] > (x[i]+(j*0.5)) )
            {
                z[i*60+j] = y[j] - (x[i]+(j*0.5));
                z[(12+i)*60+j] = y[j] - (x[i]+(j*0.5));
            }
            else
            {
                z[i*60+j] = (x[i]+(j*0.5)) - y[j];
                z[(12+i)*60+j] = (x[i]+(j*0.5)) - y[j];
            }

            if(z[i*60+j] >= 180)
            {
                z[i*60+j] = 360 - z[i*60+j];
                z[(12+i)*60+j] = 360 - z[(12+i)*60+j];
            }
        }
    }
/*
    for(int i=0;i<24;i++)
    {
        for(int j=0;j<60;j++)
        {
            printf("%.2f ",z[i*60+j]);
        }
        printf("\n");
    }

*/
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=a;i<b;i++)
    {
        for(int j=0;j<60;j++)
        {
            if(z[i*60+j] >= 88 && z[i*60+j] <= 92)
            {
                if(i < 10 && j < 10)
                    printf("0%d:0%d degree=%.2f\n",i,j,z[i*60+j]);
                else if(i < 10)
                    printf("0%d:%d degree=%.2f\n",i,j,z[i*60+j]);
                else if(j < 10)
                    printf("%d:0%d degree=%.2f\n",i,j,z[i*60+j]);
                else
                    printf("%d:%d degree=%.2f\n",i,j,z[i*60+j]);
            }
        }
    }
    if(z[b*60+0]>= 88 && z[b*60+0] <= 92)
    {
        if(b<10)
            printf("0%d:00 degree=%.2f\n",b,z[b*60]);
        else
            printf("%d:00 degree=%.2f\n",b,z[b*60]);

    }

    return 0;
}
