#include <stdio.h>
#include <stdlib.h>



int main()
{
    int n,w;
    scanf("%d %d",&n,&w);
    int val[n],wei[n];
    int plate[w+1];
    int next_plate[w+1];
    int on_plate[w+1][n+1];
    int on_next_plate[w+1][n+1];

    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&val[i],&wei[i]);
    }

    for(int j=0;j<=w;j++)
    {
        plate[j]=0;
        next_plate[j]=0;
        for(int k=0;k<=n;k++)
        {
            on_plate[j][k] = 0;
            on_next_plate[j][k] = 0;
        }
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(j-wei[i]<0)  //can't be in
            {
                next_plate[j]=plate[j];
                for(int k=0;k<=n;k++)
                {
                    on_next_plate[j][k] = on_plate[j][k];
                }
            }
            else    //can in
            {
                if(plate[j] > plate[j-wei[i]] + val[i]) //if ori is better
                {
                    next_plate[j] = plate[j];
                    for(int k=0;k<=n;k++)
                    {
                        on_next_plate[j][k] = on_plate[j][k];
                    }
                }
                else
                {
                    next_plate[j] = plate[j-wei[i]] + val[i]; //if in will be better
                    for(int k=0;k<=n;k++)
                    {
                        on_next_plate[j][k] = on_plate[j-wei[i]][k];
                    }
                    on_next_plate[j][i]=1;
                }

            }
        }
        for(int j=0;j<=w;j++)
        {
            plate[j] = next_plate[j];
            for(int k=0;k<=n;k++)
            {
                on_plate[j][k] = on_next_plate[j][k];
            }
        }

    }
    /*

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            printf("%d ",plate[i][j]);
        }
        printf("\n");
    }

    */
    printf("%d\n",plate[w]);
    for(int k=0;k<=n;k++)
    {
        if(on_plate[w][k] == 1)
            printf("%d ",k+1);
    }


    return 0;
}
