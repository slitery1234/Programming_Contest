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
        if( (t/2) % 2 == 1)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            int sum = 0;
            for(int j=0;j<t/2;j++)
            {
                cout << (j+1) * 2 << " ";
                sum += (j+1) * 2;
            }
            for(int j=0;j<t/2-1;j++)
            {
                cout << (j+1) * 2 - 1<< " ";
                sum -= ((j+1) * 2 - 1);
            }
            cout << sum << "\n";
        }

    }

    return 0;
}
