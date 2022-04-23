#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nc;
    cin >> nc;
    for(int ni=0;ni<nc;ni++)
    {
        int a,b;
        cin >> a >> b;
        int ans = 0;
        int t = b-a;

        if(t > 0)
        {
            ans += t/5;
            t = t%5;
            ans += t/2;
            t = t%2;
            ans += t/1;
            t = t%1;
        }
        if(t < 0)
        {
            t*=(-1);
            ans += t/5;
            t = t%5;
            ans += t/2;
            t = t%2;
            ans += t/1;
            t = t%1;
        }

        cout << ans << "\n";
    }
    return 0;
}
