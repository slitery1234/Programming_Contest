#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nc;
    cin >> nc;
    for(int ni=0;ni<nc;ni++)
    {
        int c,sum;
        cin >> c >> sum;
        int k = sum/c;
        int ans = 0;
        int t = sum%c;
        for(int i=0;i<t;i++)
            ans+=(k+1)*(k+1);
        for(int i=0;i<c-t;i++)
            ans+= k*k;
        cout << ans << "\n";
    }
    return 0;
}
