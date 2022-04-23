#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n,c;
    scanf("%d",&n);
    int coin[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&coin[i]);
    }
    scanf("%d",&c);
    int coins[c+1];
    int coin_usage[c+1][n];

    for(int i=0;i<=c;i++)
    {
        coins[i] = c+1;     //always larger when coin >= 1 && c = c
        for(int j=0;j<n;j++)
            coin_usage[i][j] = 0;
    }
    coins[0]=0;

    for(int i=0;i<n;i++)
    {
        for(int j=coin[i];j<=c;j++)
        {
            if(coins[j] <= coins[j-coin[i]] +1)  //If put the coin in won't better
            {
                //do nothing
            }
            else                                //If put in will better
            {
                coins[j] = coins[j-coin[i]] +1;
                for(int k=0;k<n;k++)
                    coin_usage[j][k] = coin_usage[j-coin[i]][k];
                coin_usage[j][i]++;
            }
        }
    }

    if(coins[c] == c+1)      //If can't reach the c num
        printf("-1");
    else
    {
        printf("%d\n",coins[c]);
        for(int i=0;i<n;i++)
        {
            printf("%d ",coin_usage[c][i]);
        }
    }

    return 0;
}
