#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<pair <int,int> > v;
    char ip;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> ip;
            if(ip == '1')
            {
                v.push_back(make_pair(i,j));
            }
            else if(ip != '0')
                j--;
        }
    }
    return 0;
}

