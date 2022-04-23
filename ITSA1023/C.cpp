#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    cin >> m;
    for(int ni=0;ni<m;ni++)
    {
        int n,t;
        cin >> n;
        int a[10];

        for(int i=0;i<10;i++)
            a[i] = 0;
        for(int i=0;i<n;i++)
        {
            cin >> t;
            a[t]++;
        }
        int m=0;
        for(int i=0;i<10;i++)
        {
            if(m < a[i])
                m = a[i];
        }
        cout << m << "\n";
    }

    return 0;
}

