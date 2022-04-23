#include <bits/stdc++.h>
using namespace std;


bool dfs(int start,int l, int r, int e, vector<int> edg[], int match[], int used[])
{
    if(start == -1)
        return true;

    for(int i=0;i<edg[start].size();i++)
    {
        int nei = edg[start][i];
        if(used[nei] == 1)
            continue;
        used[nei] = 1;
        if( dfs(match[nei],l,r,e,edg,match,used) )
        {
            match[nei] = start;
            return true;
        }
    }

    return false;
}
int bipartite(int l, int r, int e, vector<int> edg[])
{
    int ans = 0;
    int match[r];
    int used[r];
    for(int i=0;i<r;i++)
        match[i] = -1;
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<r;j++)
            used[j] = 0;
        if( dfs(i,l,r,e,edg,match,used) )
            ans ++;
    }
    return ans;
}


int main()
{
    int m,n,e,a,b;
    cin >> m;
    while(m != 0)
    {
        cin >> n >> e;
        vector<int> edg[m];
        for(int i=0;i<e;i++)
        {
            cin >> a >> b;
            edg[a].push_back(b);
        }
        cout << bipartite(m,n,e,edg) << "\n" ;


        cin >> m;
    }
    return 0;
}
