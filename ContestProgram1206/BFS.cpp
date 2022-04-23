#include <bits/stdc++.h>
using namespace std;

void print_ans(int n,int* ans)
{
    for(int i=0;i<n;i++)
        cout << ans[i] << " ";
    cout << "\n";
}

void BFS(int begin_node,int n,vector<int> *edge)
{
    int level[n];
    for(int i=0;i<n;i++)
        level[i] = -1;
    queue<int> q;
    q.push(begin_node);
    level[begin_node] = 0;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(int i=0;i<edge[temp].size();i++)
        {
            if(level[edge[temp][i]] == -1)
            {
                q.push(edge[temp][i]);
                level[edge[temp][i]] = level[temp] + 1;
            }
        }
    }
    print_ans(n,level);
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> edge[n];
    for(int i=0;i<m;i++)
    {
        int temp1,temp2;
        cin >> temp1 >> temp2;
        edge[temp1].push_back(temp2);
        edge[temp2].push_back(temp1);
    }
    BFS(0,n,edge);
    return 0;
}
