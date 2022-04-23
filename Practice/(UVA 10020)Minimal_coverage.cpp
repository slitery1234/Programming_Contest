//https://vjudge.net/problem/19688/origin

#include <bits/stdc++.h>
using namespace std;

pair<int,int> ip[200000];
pair<int,int> stip[200000];

bool sort_func(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.first!=p2.first)
        return p1.first<p2.first;
    else
        return p1.second>p2.second;
}


int main()
{
    int n_ca;
    cin >> n_ca;
    for(int n_i=0; n_i<n_ca; n_i++)
    {
        int m;
        cin >> m;

        int n=0;
        int inpua,inpub;
        while(cin >> inpua >> inpub)
        {
            if(inpua == 0 && inpub == 0)
                break;
            ip[n].first = inpua;
            ip[n].second = inpub;
            n++;
        }
        sort(ip,ip+n,sort_func);

        int temp = 0;
        int xx = 0;
        for(int i=0; i<n; i++)
        {
            if(temp != ip[i].first)
            {
                temp = ip[i].first;
                if( !(ip[i].first <0 && ip[i].second <0) )
                {
                    stip[xx].first = ip[i].first;
                    stip[xx].second = ip[i].second;
                    xx++;
                }
            }
            // else skip
        }

        int lend = 0;
        temp = lend;
        int ans = 1;
        vector<pair<int,int>> ansv;
        int found = 0;

        for(int prog=0; prog<xx; prog++)
        {
            if(stip[prog].first <= lend)
            {
                if(stip[prog].second > temp)
                {
                    found = 1;
                    temp = stip[prog].second;
                }
            }
            else
            {
                if(found == 0)
                {
                    ans = 0;
                    break;
                }
                else
                {
                    found = 0;
                    lend = temp;
                    ansv.push_back(stip[prog]);
                    ans++;
                    prog--;
                }
            }

            if((temp == m) && (lend!=temp))
            {
                ansv.push_back(stip[prog]);
                break;
            }
        }
        if(ans == 0)
            cout << "0\n";
        else
        {
            cout << ans << "\n";
            for(int i=0;i<ans;i++)
                cout << ansv[i].first << " " << ansv[i].second << "\n";
        }
        cout << "\n";

    }
    return 0;
}
