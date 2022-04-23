#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int edge[25][25];
int num[25];
int vis[25];

int ffind(int i)
{
    for(int j=0;j<m;j++)
    {
        if(edge[i][j] == 1 && vis[j] == 0)
        {
            vis[j] = 1;
            if(num[j] == -1 || ffind(num[j]) )
            {
                num[j] = i;
                return 1;
            }
        }
    }
    return 0;
}

int hungury()
{
    int ans = 0;
    for(int i=0;i<n;i++)
        num[i] = -1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            vis[j] = 0;
        if(ffind(i))
            ans++;
    }
    return ans;
}

int main()
{
    cin >> n;
    while(n!=0)
    {
        cin >> m;
        int t,a,b;
        cin >> t;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                edge[i][j] = 0;
        }
        for(int i=0;i<t;i++)
        {
            cin >> a >> b;
            edge[a][b] = 1;
        }
        cout << hungury() << "\n";
        cin >> n;
    }

    return 0;
}
