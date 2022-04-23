#include <bits/stdc++.h>
using namespace std;

struct path
{
    int dest;
    int value;
};

int Dij(int n,int start,int dest,vector<path> v[])
{
    int dist[n];
    for(int i=0; i<n; i++)
        dist[i] = 1e9;
    set<int> s;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[start] = 0;
    s.insert(start);
    for(int i=0; i<v[start].size(); i++)
    {
        dist[v[start][i].dest] = v[start][i].value;
        pq.push(make_pair(v[start][i].value,v[start][i].dest));
    }
    while(!pq.empty())
    {
        printf("%d %d\n",pq.top().first,pq.top().second);
        if(pq.top().second == dest)
            return dist[dest];
        if(s.count(pq.top().second) == 0)
        {
            for(int i=0; i<v[pq.top().second].size(); i++)
            {
                dist[v[pq.top().second][i].dest] = dist[pq.top().second] + v[pq.top().second][i].value;
                pq.push(make_pair(v[pq.top().second][i].value,v[pq.top().second][i].dest));
            }
            s.insert(pq.top().second);
        }
    }

}

int main()
{
    int nc;
    cin >> nc;
    for(int ni=0; ni<nc; ni++)
    {
        int n,k,a,b,c;
        cin >> n >> k >> a >> b >> c;
        vector<path> v[n];
        int val[k];
        for(int i=0; i<k; i++)
            cin >> val[i];
        for(int i=0; i<k; i++)
        {
            int a2,b2;
            cin >> a2 >> b2;
            path p;
            p.value = val[i];
            p.dest = b2-1;
            v[a2-1].push_back(p);
            p.dest = a2-1;
            v[b2-1].push_back(p);
        }
        cout << Dij(n,a,b,v) + Dij(n,b,c,v) << "\n";

    }

    return 0;
}
