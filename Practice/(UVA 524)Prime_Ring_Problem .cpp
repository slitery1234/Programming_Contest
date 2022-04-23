//https://vjudge.net/problem/19667/origin

#include <bits/stdc++.h>
using namespace std;

int n;
int tok;

int is_prime(int a)
{
    for(int i=2; i<=sqrt(a); i++)
    {
        if(a%i == 0)
            return 0;
    }
    return 1;
}

void DFS(int x,int used[],vector<int> v)
{
    tok++;
    v[tok] = x;
    used[x] = 1;

    if(tok == n-1)
    {
        if( is_prime(v[n-1]+v[0]) )
        {
            for(int i=0; i<n-1; i++)
                printf("%d ",v[i]);
            printf("%d\n",v[n-1]);
        }

        used[v[tok]] = 0;
        v[tok]=0;
        tok--;
        return;
    }
    else
    {
        for(int i=2; i<=n; i++)
        {
            if(is_prime(v[tok]+i) && used[i]==0)
                DFS(i,used,v);
        }

        /*for(int i=0; i<n-1; i++)
            printf("%d ",v[i]);
        printf("%d\t%d\tt:%d\n",v[n-1],used[n],tok);*/

        used[v[tok]] = 0;
        v[tok] = 0;
        tok--;
        return;
    }
}

int main()
{
    int t=1;
    while( scanf("%d",&n)!=EOF )
    {
        if(t!=1)
            printf("\n");
        int used[n+1];
        printf("Case %d:\n",t);
        for(int i=2; i<=n; i++)
        {
            for(int j=2; j<=n; j++)
                used[j]=0;

            vector<int> v;
            v.resize(n);
            tok=0;
            v[tok] = 1;
            used[1]=1;

            if(is_prime(v[tok]+i))
                DFS(i,used,v);
        }
        t++;
    }
    return 0;
}
