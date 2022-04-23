#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    queue<int> q;
    map<int,int> m;
    int ip;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&ip);
        if(!m.count(ip) || m[ip] == 0)
        {
            if(!m.count(ip))
                m.insert(make_pair(ip,1));
            else
                m[ip]=1;

            if(q.size()<k)
                q.push(ip);
            else
            {
                int x = q.front();
                m[x] = 0;
                q.pop();
                q.push(ip);
            }
        }
    }
    vector<int> ans;
    while(!q.empty())
    {
        ans.push_back(q.front());
        q.pop();
    }
    printf("%d\n",ans.size());
    for(int i=(int)ans.size()-1;i>=0;i--)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}
