#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nc;
    cin >> nc;
    for(int ni=0; ni<nc; ni++)
    {
        int n,k;
        cin >> n >> k;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        int pa[n/2];
        for(int i=0;i<n/2;i++)
            pa[i] = a[i] + a[n-i-1];
        map<int,int> m;
        vector<int> maxnum;
        int maxcnt=0;
        for(int i=0;i<n/2;i++)
        {
            if(m.count(pa[i]) == 0)
                m.insert(make_pair(pa[i],1));
            else
                m[pa[i]]++;
            if(m[pa[i]] > maxcnt)
            {
                maxcnt = m[pa[i]];
                maxnum.clear();
                maxnum.push_back(pa[i]);
            }
            else if(m[pa[i]] == maxcnt)
                maxnum.push_back(pa[i]);
        }

    }

    return 0;
}
