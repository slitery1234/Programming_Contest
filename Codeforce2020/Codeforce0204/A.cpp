#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nc;
    cin >> nc;
    for(int ni=0;ni<nc;ni++)
    {
        int n,a;
        int ans = 0;
        int eve = 0;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> a;
            if(a % 2)
                ans = 1;
            else
                eve = 1;
        }
        if(ans == 1 && eve == 0 && n%2 == 0 )
            cout << "NO\n";
        else if(ans == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
