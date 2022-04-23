//https://vjudge.net/problem/53681/origin

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int input;
    vector<int> v;
    v.push_back(0);
    for(int i=0;i<n;i++)
    {
        cin >> input;
        v.push_back(v.back() + input);
    }
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> input;
        vector<int>::iterator ans = lower_bound(v.begin(),v.end(),input);
        cout << ans-v.begin() << "\n";
    }

    return 0;
}
