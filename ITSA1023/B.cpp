#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    cin >> m;
    for(int ni=0;ni<m;ni++)
    {
        double a,b;
        cin >> a >> b;
        double d = (a-10)*(a-10) + (b-10)*(b-10);
        int k = (int)sqrt(d);
        if(abs(sqrt(d) - k) < 1e-6 && k > 0)
            k--;
        if(k < 10)
            cout << 10-k << "\n";
        else
            cout << "0\n";
    }

    return 0;
}
