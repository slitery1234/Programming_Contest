#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<n;i++)
    {
        set<string> s;
        string ipt[a[i]];
        int ans = 0;
        for(int j=0;j<a[i];j++)
        {
            cin >> ipt[j];
            if(s.count(ipt[j]) == 0)
                s.insert(ipt[j]);
            else
                s.erase(ipt[j]);
        }
        for(int j=0;j<a[i];j++)
        {
            if(s.count(ipt[j]) == 1)
            {
                s.erase(ipt[j]);
                ans ++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
