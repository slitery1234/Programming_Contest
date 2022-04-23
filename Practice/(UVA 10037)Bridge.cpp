//https://vjudge.net/problem/21232/origin
#include <bits/stdc++.h>
using namespace std;


int n;
vector<int> ip;
vector<int> othsid;
queue<pair<int,int>> ansq;
int ans;

void cross(int a,int b)
{
    ans += max(a,b);
    othsid.push_back(a);
    othsid.push_back(b);
    ansq.push(make_pair(a,b));
    return;
}
int cross(int a)
{
    ans += a;
    for(int i=0; i<othsid.size(); i++)
    {
        if(othsid[i] == a)
        {
            swap(othsid[i],othsid.back());
            othsid.resize(othsid.size() -1);
            ansq.push(make_pair(a,-1));
            return 0;
        }
    }
    return -1;
}


int test(int siz)
{
    sort(ip.begin(),ip.end());
    if(siz >= 4)
    {
        int result=0;
        int fir,sec,sfir,ssec;

        swap(ip[1],ip[ip.size()-3]);
        swap(ip[0],ip[ip.size()-4]);

        fir = ip[ip.size()-1];
        sec = ip[ip.size()-2];
        ssec = ip[ip.size()-3];
        sfir = ip[ip.size()-4];
        ip.resize(ip.size()-4);

        //--------------------------------------------
        if(sec+sfir < 2*ssec)
        {
            cross(sfir,fir);
            cross(sfir);
            cross(sfir,sec);
            cross(sfir);

        }
        else
        {
            cross(sfir,ssec);
            cross(sfir);
            cross(sec,fir);
            cross(ssec);
        }
        ip.push_back(sfir);
        ip.push_back(ssec);
        return test(siz-2);
        //---------------------------------------------
    }
    else if(siz == 3)
    {
        cross(ip[0],ip[2]);
        cross(ip[0]);
        cross(ip[0],ip[1]);
        return 1;
    }
    else if(siz == 2)
    {
        cross(ip[0],ip[1]);
        return 1;
    }
    else if(siz == 1)
    {
        cross(ip[0]);
        return 1;
    }
}

int main()
{
    int n_c;
    cin >> n_c;
    for(int n_i=0; n_i<n_c; n_i++)
    {
        ans = 0;
        cin >> n;
        ip.resize(n);
        for(int i=0; i<n; i++)
            cin >> ip[i];

        if(n_i!=0)
            cout << "\n";
        test(n);
        cout << ans << "\n";
        while(!ansq.empty())
        {
            if(ansq.front().second != -1)
                cout << ansq.front().first << " " << ansq.front().second << "\n";
            else
                cout << ansq.front().first << "\n";
            ansq.pop();
        }
    }
    return 0;
}
