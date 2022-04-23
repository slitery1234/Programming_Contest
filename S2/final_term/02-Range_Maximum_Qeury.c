#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int func(int a,int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    int n_case;
    scanf("%d",&n_case);
    for(int n_c=0;n_c<n_case;n_c++)
    {
        int n,l;
        int K=25;
        scanf("%d%d",&n,&l);
        int arr[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);

        int log[n+1];
        log[1] = 0;
        for(int i=2;i<=n;i++)
            log[i] = log[i/2]+1;

        int st[n][K+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=K;j++)
                st[i][j]=0;
        }

        //dynamic programming initialize
        for(int i=0;i<n;i++)
        {
            st[i][0] = arr[i];
        }

        //dynamic programming
        for(int j=1;j<=K;j++)
        {
            // "<<" means every bit moves left
            // so "x << 1" is the same as x*2
            // and 1 << n means 2^n
            for(int i=0; i + (1<<j) <=n ;i++)
            {
                st[i][j] = func(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            }
        }
/*
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=K;j++)
                printf("%d ",st[i][j]);
            printf("\n");
        }
*/
        //i from 0 to n found maximum value at i~(i+l)
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int L = i;
            int R = L+l;
            if(R >= n)
                R = n-1;
            int j = log[R-L+1];
            int x = func(st[L][j] , st[R-(1<<j)+1][j]);

            if( x - arr[i] > ans)
                ans = x-arr[i];
        }
        printf("%d\n",ans);

    }

}
