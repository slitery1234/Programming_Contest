#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_ARR_SIZ 250
#define MAX_INT 100000000

int capa[MAX_ARR_SIZ][MAX_ARR_SIZ];
int flow[MAX_ARR_SIZ][MAX_ARR_SIZ];

void update(int m,int prenode[],int t)
{
    int tmp = t;

    while(prenode[tmp] != -1)
    {
        flow[prenode[tmp]][tmp] += m;
        flow[tmp][prenode[tmp]] -= m;
        tmp = prenode[tmp];
    }
    return;
}

int BFS(int s,int t,int n)
{
    int prenode[n];
    int remain[n];
    for(int i=0; i<n; i++)
    {
        prenode[i] = -1;
        remain[i] = 0;
    }
    remain[s] = MAX_INT;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(int i=0; i<n; i++)
        {
            if(remain[i] == 0 && capa[f][i] > flow[f][i])
            {
                q.push(i);
                prenode[i] = f;
                remain[i] = min(remain[f], capa[f][i] - flow[f][i]);
            }
        }
    }

    if(remain[t] == 0)
        return -1;

    update(remain[t],prenode,t);
    return remain[t];
}

int maxflow(int s,int t,int n)
{
    int ans = 0;
    int prenode[n];
    int m = BFS(s,t,n);

    while(m != -1)
    {
        ans += m;
        m =BFS(s,t,n);
    }
    return ans;
}

int main()
{
    int m,n,a,b,c;
    while(cin >> m >> n)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                capa[i][j] = 0;
                flow[i][j] = 0;
            }
        }
        for(int i=0; i<m; i++)
        {
            cin >> a >> b >> c;
            capa[a-1][b-1] = c;
        }
        cout << maxflow(0,n-1,n) << "\n";
    }
}
