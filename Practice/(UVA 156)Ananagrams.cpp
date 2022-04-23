//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=92

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int ans;
    while(cin >> n)
    {
        if (n == 0)
            break;
        ans = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        int x;
        for(int i=0;i<n;i++)
        {
            cin >> x;
            pq.push(x);
        }
        while( pq.size() > 1)
        {
            x = pq.top();
            pq.pop();
            x += pq.top();
            pq.pop();
            pq.push(x);
            ans += x;
        }
        cout << ans << "\n";
    }
}
