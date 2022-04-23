#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v[n];
    int a,b;
    for(int i=0;i<n-1;i++)
    {
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }

    int dis[n];
    for(int i=0;i<n;i++)
        dis[i] = -1;

    queue<int> q;
    q.push(0);
    dis[0] = 0;
    int maxdis = -1;
    int maxi = 0;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(auto x:v[f])
        {
            if(dis[x] == -1){
                q.push(x);
                dis[x] = dis[f] + 1;
                if(maxdis < dis[x]){
                    maxdis = dis[x];
                    maxi = x;
                }
            }
        }
    }
    int prev[n];
    for(int i=0;i<n;i++){
        dis[i] = -1;
        prev[i] = -1;
    }
    q.push(maxi);
    dis[maxi] = 0;
    maxdis = -1;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(auto x:v[f])
        {
            if(dis[x] == -1){
                q.push(x);
                dis[x] = dis[f] + 1;
                prev[x] = f;
                if(maxdis < dis[x]){
                    maxdis = dis[x];
                    maxi = x;
                }
            }
        }
    }
    int now = maxi;
    int ans;
    if(maxdis % 2 == 1){
        int cnt = 0;
        while(1){
            if(cnt == 0){
            if(dis[now] == maxdis / 2 || dis[now] == maxdis / 2 + 1){
                ans = now;
                cnt ++;
            }}
            else{
                if(now < ans)
                    cout << now+1 << "\n";
                else
                    cout << ans+1 << "\n";
                return 0;
            }
            now = prev[now];
        }
    }
    else{
        while(1){
            if(dis[now] == maxdis / 2){
                cout << now+1 << "\n";
                return 0;
            }
            now = prev[now];
        }
    }


    return 0;
}
