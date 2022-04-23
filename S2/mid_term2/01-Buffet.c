#include <stdio.h>
#include <stdlib.h>



int main()
{
    int n,w;
    scanf("%d %d",&n,&w);
    int val[n],wei[n];
    int plate[n+1][w+1];
    int on_plate[n+1][w+1][n+1];

    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&val[i],&wei[i]);
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            plate[i][j]=0;
            for(int k=0;k<=n;k++)
            {
                on_plate[i][j][k]=0;
            }
            //on_plate[i][j][i]=1;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(j-wei[i]<0)  //can't be in
            {
                plate[i+1][j]=plate[i][j];
                for(int k=0;k<n;k++)
                {
                    on_plate[i+1][j][k]=on_plate[i][j][k];
                }
            }
            else    //can in
            {
                if(plate[i][j] > plate[i][j-wei[i]] + val[i]) //if ori is better
                {
                    plate[i+1][j] = plate[i][j];
                    for(int k=0;k<n;k++)
                    {
                        on_plate[i+1][j][k]=on_plate[i][j][k];
                    }
                }
                else                                           //if in will be better
                {
                    plate[i+1][j] = plate[i][j-wei[i]] + val[i];
                    for(int k=0;k<n;k++)
                    {
                        on_plate[i+1][j][k]=on_plate[i][j][k];
                    }
                    on_plate[i+1][j][i]=1;

                }
            }

            for(int k=0;k<=n;k++)
            {
                printf("%d",on_plate[i][j][k]);
            }
            printf("\n");
        }
    }

    /*
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            printf("%d ",plate[i][j]);
        }
        printf("\n");5 18
2 5
6 2
2 4
1 6
3 7
    }
    */

    printf("%d\n",plate[n][w]);
    for(int k=0;k<n;k++)
    {
        if(on_plate[n][w][k]==1)
            printf("%d",k+1);
        else
        {

        }
    }


    return 0;
}
