#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0;
    scanf("%d",&n);
    while(n--)
    {
        int k=0;
        long long int x=1;
        scanf("%d",&k);
        for(int i=1; i<=k; i++)
        {
            x=x*i;
            if(x>=1000000007)
                x=x%1000000007;
        }
        printf("%lld\n",x);
    }
}
