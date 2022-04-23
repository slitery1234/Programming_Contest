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

        if(n % 2 == 0)
        {
            for(int i=0;i<(n/2);i++)
                cout << "1";
        }
        else if(n % 2 == 1)
        {
            cout << "7";
            for(int i=0;i<(n/2)-1;i++)
                cout << "1";
        }
        cout << "\n";
    }
    return 0;
}
