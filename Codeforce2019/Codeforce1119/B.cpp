#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nc;
    cin >> nc;
    for(int ni=0;ni<nc;ni++)
    {
        int n,m;
        cin >> n >> m;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        if(n == 2 || m < n )
        {
            cout << "-1\n";
            continue;
        }

        int cost = 0;
        int min1 = 0x3f3f3f3f,min2 = 0x3f3f3f3f;
        int mini1 = 0,mini2 = 0;
        for(int i=0;i<n;i++)
        {
            cost += 2*a[i];
            if(a[i] < min1)
            {
                min2 = min1;
                mini2 = mini1;
                min1 = a[i];
                mini1 = i;
            }
            else if(a[i] < min2)
            {
                min2 = a[i];
                mini2 = i;
            }
        }
        cost += (m-n)*(min1+min2);

        cout << cost << "\n";
        for(int i=0;i<n-1;i++)
        {
            cout << i+1 << " " << i+2 << "\n";
        }

        cout << n << " 1\n" ;
        for(int i=0;i<m-n;i++)
            cout << mini1+1 << " " << mini2+1 << "\n";
    }
    return 0;
}
