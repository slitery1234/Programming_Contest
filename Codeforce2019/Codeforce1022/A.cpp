#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nc;
    cin >> nc;
    for(int ni=0;ni<nc;ni++)
    {
        int n;
        cin >> n;
        set<int> s;
        int ip,ans;
        ans = 1;
        for(int i=0;i<n;i++)
        {
            cin >> ip;
            if(s.count(ip) == 0)
                s.insert(ip);

            if(s.count(ip-1)==1 || s.count(ip+1)==1)
            {
                ans = 2;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
