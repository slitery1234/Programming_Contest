//https://vjudge.net/problem/21897/origin

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int input[4][5000];
int a[5000*5000],b[5000*5000];

int main()
{
    while(scanf("%d",&n) != EOF)
    {

        for(int i=0; i<n; i++)
            scanf("%d%d%d%d",&input[0][i],&input[1][i],&input[2][i],&input[3][i]);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                a[i*n+j]=input[0][i] + input[1][j];
                b[i*n+j]= -1 * (input[2][i] + input[3][j]);
            }
        }
        sort(a,a+n*n);
        sort(b,b+n*n);
/*
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    printf("%d %d\n",a[i*n+j],b[i*n+j]);
                }
            }
*/
        int ans=0;
        for(int i=0;i<n*n;i++)
        {
            int *x = lower_bound(b,b+n*n,a[i]);
            int *y = upper_bound(b,b+n*n,a[i]);
            ans += (y-x);

        }
        printf("%d\n",ans);
    }
    return 0;
}
