#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        int x = 4;
        while(t % (x-1) != 0)
            x*=2;

        cout << t/(x-1) << "\n";
    }

    return 0;
}
