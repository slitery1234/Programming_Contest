#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nc;
    cin >> nc;
    for(int ni=0; ni<nc; ni++)
    {
        int n;
        cin >> n;
        char c[n];
        pair<int,int> p,ans;
        map<pair <int,int>,int> ss;
        p.first = 0;
        p.second = 0;
        ans.first = -1;
        ans.second = 200000;
        ss.insert(make_pair(p,1));
        for(int i=0;i<n;i++)
            cin >> c[i];

        for(int i=0;i<n;i++)
        {
            if(c[i] == 'U')
                p.second++;
            if(c[i] == 'D')
                p.second--;
            if(c[i] == 'L')
                p.first--;
            if(c[i] == 'R')
                p.first++;

            if(ss.count(p) == 1)
            {
                if(ans.second - ans.first > i+1 - ss[p])
                {
                    ans.first = ss[p];
                    ans.second = i+1;
                    ss[p] = i+1;
                }
            }
            else
                ss.insert(make_pair(p,i+2));

        }
        if(ans.first == -1)
            cout << "-1\n";
        else
        {
            cout << ans.first << " " << ans.second << "\n";
        }

    }
    return 0;
}
