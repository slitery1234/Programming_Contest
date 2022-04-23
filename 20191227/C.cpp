#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << n << " 0 ";
    for(int i=1;i<=4;i++)
    {
        cout << n+i << " -" << n+i << " ";
    }
}
