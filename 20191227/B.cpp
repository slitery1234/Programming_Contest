#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    map<int,int> m;
    int a,b,t,ans=0;;
    cin >> a >> b;
    for(int i=0;i<b;i++)
    {
        cin >> t;
        if(m[t] == 1)
        {
            ans++;
            continue;
        }

        if(q.size() < a)
        {
            q.push(t);
            if(m.count(t) == 1)
                m[t] = 1;
            else
                m.insert(make_pair(t,1));
        }
        else
        {
            int f = q.front();
            m[f] = 0;
            q.pop();
            q.push(t);
            if(m.count(t) == 1)
                m[t] = 1;
            else
                m.insert(make_pair(t,1));
        }
    }
    cout << ans << "\n";
}
