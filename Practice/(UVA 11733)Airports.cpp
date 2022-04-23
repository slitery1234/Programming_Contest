#include <bits/stdc++.h>
using namespace std;


struct road
{
    int poi1,poi2;
    int cost;
};
bool sort_func(road r1,road r2)
{
    return r1.cost < r2.cost;
}


vector<road> input;
int parent[20000];


int ufind(int a)
{
    if(a == parent[a])
        return parent[a];
    else
    {
        parent[a] = ufind(parent[a]);
        return parent[a];
    }
}
int uunion(int a,int b)
{
    int x = ufind(a);
    int y = ufind(b);
    if(x != y)
        parent[x] = y;
    return 0;
}

int main()
{
    int nc;
    cin >> nc;
    for(int ni=0;ni<nc;ni++)
    {
        input.clear();
        int n,tim,apcost;
        cin >> n >> tim >> apcost;
        int ip1,ip2,ip3;
        for(int i=0;i<tim;i++)
        {
            cin >> ip1 >> ip2 >> ip3;
            road ipr;
            ipr.poi1= ip1-1;
            ipr.poi2= ip2-1;
            ipr.cost = ip3;
            if(ipr.cost < apcost)
                input.push_back(ipr);
        }
        for(int i=0;i<n;i++)
            parent[i] = i;
        sort(input.begin(),input.end(),sort_func);

        int roadcost=0;
        int apcount=0;
        int trees[n];

        for(int i=0;i<input.size();i++)
        {
            if(ufind(input[i].poi1) != ufind(input[i].poi2))
            {
                uunion(input[i].poi1,input[i].poi2);
                roadcost += input[i].cost;
            }
        }
        for(int i=0;i<n;i++)
            trees[i] = 0;
        for(int i=0;i<n;i++)
            trees[ufind(parent[i])] = 1;
        for(int i=0;i<n;i++)
            apcount += trees[i];

        cout << "Case #" << ni+1 << ": " << apcount*apcost + roadcost << " " << apcount << "\n";

    }
    return 0;
}

