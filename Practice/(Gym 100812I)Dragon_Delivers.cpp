#include <iostream>
using namespace std;

int main()
{
    int n,dc,tc;
    scanf("%d%d%d",&n,&dc,&tc);
    long long int tim[n],dp[n],sumtim[n+1];
    sumtim[0]=0;
    for(int i=0; i<n; i++)
    {
        scanf("%lld",&tim[i]);
        dp[i]=0x3f3f3f3f;
        sumtim[i+1] = sumtim[i] + tim[i];
    }
    dp[0]=0;

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            dp[i] = min(dp[i],dp[j] + ((i-j)*tim[i] - (sumtim[i+1] - sumtim[j])) *tc + dc);
            printf("%d %d :%lld %lld\n",i,j,dp[i],dp[j]);
        }
    }

    printf("%lld\n",dp[n-1]);

    return 0;
}
