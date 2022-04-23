//https://vjudge.net/problem/460313/origin

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,n2,input2;
    cin >> n;
    int input[n];
    for(int i=0;i<n;i++)
        cin >> input[i];
    sort(input,input+n);
    cin >> n2;
    for(int i=0;i<n2;i++)
    {
        cin >> input2;
        int *ans = upper_bound(input,input+n,input2);
        cout << ans-input << "\n";
    }

    return 0;
}
