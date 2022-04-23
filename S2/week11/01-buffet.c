#include <stdio.h>
#include <stdlib.h>



int main()
{
    int n,w;
    scanf("%d %d",&n,&w);
    int val[n],wei[n];
    int plate[n+1][w+1];

    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&val[i],&wei[i]);
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            plate[i][j]=0;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(j-wei[i]<0)  //can't be in
                plate[i+1][j]=plate[i][j];
            else    //can in
            {
                if(plate[i][j] > plate[i][j-wei[i]] + val[i]) //if ori is better
                    plate[i+1][j] = plate[i][j];
                else
                    plate[i+1][j] = plate[i][j-wei[i]] + val[i]; //if in will be better
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
    printf("%d",plate[n][w]);


    return 0;
}
