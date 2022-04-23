//https://vjudge.net/problem/17547/origin

#include <bits/stdc++.h>
using namespace std;


/*
int exch(int n,int m)
{
    if(n == 0)
        return 1;
    else if( n < 0 || m == 0)
        return 0;
    else
        return(exch(n-coin[m],m) + exch(n,m-1));
}
*/
int main()
{
    int n;
    while(cin >> n)
    {
        int ans[5][n+1];
        int coin[5]={1,5,10,25,50};

        for(int i=0;i<5;i++)
        {
            for(int j=0;j<=n;j++)
            {
                ans[i][j] = 1;
            }
        }

        for(int i=1;i<5;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(j >= coin[i])
                    ans[i][j] = ans[i][j-coin[i]] + ans[i-1][j] ;
                else
                    ans[i][j] = ans[i-1][j];
            }
        }
        cout << ans[4][n] << "\n";
    }
    return 0;
}
