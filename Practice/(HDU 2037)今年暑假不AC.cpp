//https://vjudge.net/problem/17491/origin

#include <iostream>
#include <algorithm>
using namespace std;

bool sort_func(pair<int,int> p1,pair<int,int> p2)
{
    return p1.second<p2.second;
}

int main()
{
    int n;
    while(cin >> n)
    {
        if(n == 0)
            break;
        pair<int,int> ip[n];
        int ans=0;
        int maxtime=0;
        int temp;
        for(int i=0; i<n; i++)
        {
            cin >> ip[i].first >> ip[i].second;
            if(ip[i].second >= maxtime)
                maxtime = ip[i].second;
        }
        while(1)
        {
            int found = 0;
            sort(ip,ip+n,sort_func);

            for(int i=0; i<n; i++)
            {
                if(ip[i].first != -1)
                {
                    //cout << ip[i].first << ip[i].second << "\n";
                    temp = ip[i].second;
                    ans++;
                    found = 1;
                    break;
                }
            }

            if(found == 0)
                break;
            else
            {
                for(int i=0; i<n; i++)
                {
                    if(ip[i].first < temp)
                        ip[i].first = -1;
                }
            }
        }
        cout << ans << "\n";
    }


    return 0;
}
