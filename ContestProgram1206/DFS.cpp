#include <bits/stdc++.h>
using namespace std;

void DFS(int index,int *used,vector<int> *edge)
{
    if(used[index])
        return;
    used[index] = 1;
    cout << index << " ";
    for(int i=0;i<edge[index].size();i++)
    {
        if(used[edge[index][i]] == 0)
            DFS(edge[index][i],used,edge);
    }
    return;
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
    int used[n];
    for(int i=0;i<n;i++)
        used[i] = 0;
    for(int i=0;i<n;i++)
        DFS(i,used,edge);
    return 0;
}
