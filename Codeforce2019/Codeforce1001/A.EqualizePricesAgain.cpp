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
        int sum=0,ip;
        for(int i=0;i<n;i++)
        {
            cin >> ip;
            sum += ip;
        }
        cout << sum/n + 1 - !(sum%n) << "\n";
    }
    return 0;
}
