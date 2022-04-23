#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

struct st
{
    int poi;
    int dist;
};

int nc,n;
int dis[2000],used[2000];
vector<st> road[2000];
queue<int> q;

int Dijkstra(int a)
{
    for(int i=0;i<road[a].size();i++)
    {
        if( dis[road[a][i].poi] > dis[a]+road[a][i].dist)
        {
            dis[road[a][i].poi] = dis[a]+road[a][i].dist;
            if(used[road[a][i].poi] == 0)
            {
                used[road[a][i].poi] = 1;
                q.push(road[a][i].poi);
            }
        }
    }
    return 0;
}

int BFS()
{
    while(!q.empty())
    {
        int a = q.front();
        Dijkstra(a);
        q.pop();
    }
}

int main()
{
    cin >> nc >> n;

    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(used,0,sizeof(used));
    int ipa,ipb,ipc;
    for(int i=0; i<nc; i++)
    {
        cin >> ipa >> ipb >> ipc;
        st s1,s2;
        s1.poi = ipb;
        s1.dist = ipc;
        s2.poi = ipa;
        s2.dist = ipc;
        road[ipa].push_back(s1);
        road[ipb].push_back(s2);
    }
    dis[n] = 0;
    used[n] = 1;
    q.push(n);

    BFS();
    cout << dis[1] << "\n";
    return 0;
}
