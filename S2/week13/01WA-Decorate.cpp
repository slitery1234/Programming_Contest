#include <bits/stdc++.h>
using namespace std;

int test(int n, int color[], int index, vector <int> v[])
{
    if(color[index] == -1)
        color[index] = 1;

    if(color[index] == 1)
    {
        for(int i=0;i<v[index].size();i++)
        {
            if(color[v[index][i]] == 1)
                return -1;

            color[v[index][i]] = 0;
            int t = test(n,color,v[index][i],v);

            if(t == -1)
                return -1;
        }
    }
    else if(color[index] == 0)
    {
        for(int i=0;i<v[index].size();i++)
        {
            if(color[v[index][i]] == 0)
                return -1;

            color[v[index][i]] = 1;
            int t = test(n,color,v[index][i],v);

            if(t == -1)
                return -1;
        }
    }

    return 0;
}

int main()
{
    int n;
    scanf("%d",&n);
    vector <int> v[n];
    int color[n];    // 0 means white,1 means black
    int x,y;
    for(int i=0;i<n;i++)
    {
        color[i] = -1;   //-1 means unset
    }

    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&x,&y);
        v[x-1].push_back(y-1);
        //v[y-1].push_back(x-1);
    }


    int t = 0;
    for(int i=0;i<n;i++)
    {
        if(color[i] == -1)
            t = test(n,color,0,v);
        if(t == -1)
            break;
    }

    if(t == -1)
        printf("-1");
    else
    {
        for(int i=0;i<n;i++)
        {
            if(color[i] == 1)
                printf("%d ",i+1);
        }
    }

    return 0;
}
