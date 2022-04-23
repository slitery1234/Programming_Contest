#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int dis[n+2][n+2];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dis[i][j] = 0x3f3f3f3f;
        }
    }

    for(int i=0;i<=n;i++)
        dis[i][i]=0;
    for(int i=0;i<m;i++)
    {
        int ni;
        scanf("%d",&ni);
        int ip[ni];
        for(int j=0;j<ni;j++)
            scanf("%d",&ip[j]);

        for(int j=0;j<ni-1;j++)
        {
            for(int k=j+1;k<ni;k++)
            {
                dis[ip[j]][ip[k]] = 1;
                dis[ip[k]][ip[j]] = 1;
            }
        }
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dis[i][j]>dis[i][k]+dis[k][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
            }
        }
    }

    int min_sum=0x3f3f3f3f,sum=0;
    for(int i=1;i<=n;i++)
    {
        sum=0;
        for(int j=1;j<=n;j++)
        {
            sum+=dis[i][j];
        }
        if(min_sum > sum)
            min_sum = sum;
    }
    printf("%d\n",min_sum*100/(n-1));
    return 0;
}
