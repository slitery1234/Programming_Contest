#include <bits/stdc++.h>
using namespace std;

void print_graph(int index,vector<int> *edge)
{
    cout << index << " : ";
    for(int i=0;i<edge[index].size();i++)
        cout << edge[index][i] << " ";
    cout << "\n";
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
    for(int i=0;i<n;i++)
        print_graph(i,edge);
    return 0;
}
