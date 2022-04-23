#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int,int> m;
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    queue<int> q;
    int ans = 0;
    vector<int> ans_arr;

    for(int i=0; i<n; i++)
    {

        if(m.count(a[i]) == 0 || m[a[i]] == 0)
        {
            if(a[i] > 0)
                m.insert(make_pair(a[i],1));
            else if(a[i] < 0)
            {
                if(m.count( (-1) * a[i] ) == 0 || m[(-1) * a[i]] == 0)
                {
                    ans = -1;
                    break;
                }
                else
                {
                    m[(-1)*a[i]] = -1;
                }
            }
        }
        else
        {
            int t = 0;
            while(!q.empty())
            {
                int tmp = q.front();
                q.pop();
                if(m[tmp] != -1)
                    ans = -1;
                t += 2;
            }
            m.clear();
            if(ans == -1)
                break;
            else
                ans_arr.push_back(t);
            m.insert(make_pair(a[i],1));
        }
        if(a[i] > 0)
            q.push(a[i]);
    }

    int t = 0;
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();

        if(m[tmp] != -1)
            ans = -1;
        t += 2;
    }


    m.clear();
    if(ans != -1)
        ans_arr.push_back(t);



    if(ans == -1)
        printf("-1\n");
    else
    {
        printf("%d\n",ans_arr.size());
        for(int i=0; i<ans_arr.size(); i++)
            printf("%d ",ans_arr[i]);
        printf("\n");
    }
    return 0;
}

