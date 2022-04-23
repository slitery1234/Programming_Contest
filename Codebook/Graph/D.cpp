#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;
int n,m,w;
vector<pair<int,int> > input[1000];
int test[1000];
int dis[1000];
int judge[1000];


int BFS(int st)
{
    queue<int> q;
    q.push(st);
    test[st] = 1;
    dis[st] = 0;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        test[x] = 0;
        for(int i=0; i<input[x].size(); i++)
        {
            int poi = input[x][i].first;
            int leng = input[x][i].second;
            if(dis[poi] > dis[x] + leng)
            {
                dis[poi] = dis[x] + leng;

                judge[poi] = judge[x] + 1;
                if(judge[poi] > n+1)
                    return 0;

                if(test[poi] == 0)
                {
                    test[poi] = 1;
                    q.push(poi);
                }
            }
        }
    }
    return 1;
}

int main()
{
    int nc;
    scanf("%d",&nc);
    for(int ni=0; ni<nc; ni++)
    {
        scanf("%d%d%d",&n,&m,&w);
        int ipa,ipb,ipc;
        for(int i=0; i<=n; i++)
            input[i].clear();
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&ipa,&ipb,&ipc);
            input[ipa].push_back(make_pair(ipb,ipc));
            input[ipb].push_back(make_pair(ipa,ipc));
        }
        for(int i=0; i<w; i++)
        {
            scanf("%d%d%d",&ipa,&ipb,&ipc);
            input[ipa].push_back(make_pair(ipb,-ipc));
        }

        int ans;
        for(int j=1;j<=n;j++)
        {
            test[j]=0;
            dis[j]=0x3f3f3f3f;
            judge[j]=0;
        }
        ans = BFS(1);

        if(ans == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
