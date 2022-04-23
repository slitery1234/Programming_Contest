#include <bits/stdc++.h>
using namespace std;

int func(int n)
{
    int x = n/10;
    int ans = n;
    while( (n%10 + x) >=10)
    {
        ans += x;
        n = n%10 + x;
        x = n/10;
    }
    ans += x;
    return ans;
}
int main()
{
    int nc;
    cin >> nc;
    for(int ni=0; ni<nc; ni++)
    {
        int n;
        cin >> n;
        cout << func(n) << "\n";
    }
    return 0;
}
