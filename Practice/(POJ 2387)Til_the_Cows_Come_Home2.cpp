#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;


int nc,n;
int dis[2000],used[2000];
vector< pair<int,int> > road[2000];
priority_queue< pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > > pq;

bool sort_func(st a,st b)
{
    return a.dist < b.dist;
}

int main()
{
    scanf("%d%d",&nc,&n);

    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(used,0,sizeof(used));
    for(int i=0;i<nc;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&s.dist);
        road[a].push_back(s);
        road[b].push_back(s);
    }

    return 0;
}
