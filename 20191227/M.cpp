#include <bits/stdc++.h>
using namespace std;

bool func(pair<int,int> p1, pair<int,int> p2)
    return p1 > p2

int main()
{
    int n,m;
    pair<int,int> value[i];
    int w[n],v[n],k[n];
    cin >> n >> m;
    m = m*1000;
    for(int i=0;i<n;i++)
    {
        cin >> w[i] >> v[i] >> k[i];
        value[i] = make_pair( (v[i] / w[i]),i);
    }
    sort(value.begin(),value.end(),func);

    int a = 0;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(a + (w[value[i].second] * k[value[i].second]) < w)
        {
            a += w[value[i].second] * k[value[i].second];
            ans += v[value[i].second] * k[value[i].second];
        }
        else
        {
            for(int i=0;i<w)
        }
    }
}
