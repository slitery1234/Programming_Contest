#include <bits/stdc++.h>
using namespace std;

int main()
{
    int length;
    scanf("%d",&length);
    while(length != 0)
    {
        int n;
        scanf("%d",&n);
        int poi[n+2];
        for(int i=1; i<=n; i++)
            scanf("%d",&poi[i]);
        int dpcost[n+1][length+1];
        int dpleng[n+1][length+1];

        poi[0] = 0;
        poi[n+1] = length;
        memset(dpcost,0x3f3f3f3f,sizeof(dpcost));
        for(int j=0; j<=length; j++)
            dpcost[0][j] = 0;
        for(int j=0; j<=length; j++)
            dpleng[0][j] = length;

        for(int i=1; i<=n; i++)
        {
            for(int k=0; k<=n+1; k++)
            {
                for(int j=poi[k]; j<=length; j++)
                {
                    if(dpcost[i][j]  > dpcost[i-1][j-poi[k]] + dpleng[i-1][j-poi[k]])
                    {
                        dpcost[i][j] = dpcost[i-1][j-poi[k]] + dpleng[i-1][j-poi[k]];
                        dpleng[i][j] = dpleng[i-1][j-poi[k]] - poi[k];
                    }
                }
            }
        }

        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=length; j++)
            {
                printf("%d ",dpleng[i][j]);
            }
            printf("\n");
        }

        scanf("%d",&length);
    }
    return 0;
}
