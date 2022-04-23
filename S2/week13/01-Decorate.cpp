#include <bits/stdc++.h>
using namespace std;

int link_ab(int a,int b,int color[],int n)
{
    //printf("%d %d\n",a+1,b+1);
    if(color[b] == -1)
    {
        if(color[a] == 1)
            color[b]=0;
        else if(color[a] == 0)
            color[b]=1;
        return 0;
    }
    else
    {
        if(color[a]==color[b])
            return -1;
        else
            return 0;
    }
}

int link(int index,vector <int> v[],int color[],int n,int is_test[])
{
    is_test[index] = 1;
    int t=0;
    if(color[index] == (-1) && v[index].size()!=0)
        color[index]=1;

    for(int i=0; i<v[index].size(); i++)
    {
        t = link_ab(index,v[index][i],color,n);
        if(t == -1)
            return -1;

        if(!is_test[v[index][i]])
            t = link(v[index][i],v,color,n,is_test);
        if(t == -1)
            return -1;
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
    int is_test[n];
    for(int i=0;i<n;i++)
    {
        color[i] = -1;   //-1 means unset
        is_test[i] = 0;
    }

    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&x,&y);
        v[x-1].push_back(y-1);
        v[y-1].push_back(x-1);
    }
//----------------------------
    int t;
    for(int i=0;i<n;i++)
    {
        if(!is_test[i])
           t = link(i,v,color,n,is_test);
        if(t == -1)
            break;
    }

    if(t == -1)
        printf("-1");
    else
    {
        for(int i=0;i<n;i++)
        {
            if(color[i] || color[i]==-1)
                printf("%d ",i+1);
        }
    }

    return 0;
}
