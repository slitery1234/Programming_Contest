#include <bits/stdc++.h>
using namespace std;


struct walk
{
    int vertex;
    int dist;
};

void BFS(int i,int d,int n,vector<int> edge[],queue<walk> dis,int is_test[],int ans[])
{
    walk w;

    while(!dis.empty())
    {
        w = dis.front();
        dis.pop();
        i = w.vertex;
        d = w.dist;

        for(int j=0; j<edge[i].size(); j++)
        {
            if(is_test[edge[i][j]] == 0)
            {
                //printf("%d %d\n",i+1,edge[i][j]+1);
                is_test[edge[i][j]] = 1;
                w.vertex = edge[i][j];
                w.dist = d+1;
                dis.push(w);
            }
        }

        ans[i] = d;
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    vector<int> edge[n];
    int is_test[n];
    int ans[n];
    for(int i=0; i<n; i++)
    {
        is_test[i]=0;
        ans[i]=-1;
    }
    ans[1]=0;
    is_test[1]=1;

    int x,y;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d",&x,&y);
        edge[x-1].push_back(y-1);
        edge[y-1].push_back(x-1);
    }

    queue<walk> dis;
    walk w;
    w.dist=0;
    w.vertex=1;
    dis.push(w);
    BFS(w.vertex,w.dist,n,edge,dis,is_test,ans);

    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);

    return 0;
}
