#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct line
{
    int poi1,poi2;
    int leng;
};

bool sort_func(line l1,line l2)
{
    return l1.leng < l2.leng;
}

int ufind(int a,int parent[])
{
    if(a == parent[a])
        return parent[a];
    else
        return ufind(parent[a],parent);
}

int main()
{
    int n;
    while(cin >> n)
    {
        if(n==0)
            return 0;

        vector<line> input;
        for(int i=0;i<n-1;i++)
        {
            char c1,c2;
            int n2;
            cin >> c1 >> n2;
            for(int ii=0;ii<n2;ii++)
            {
                int l;
                cin >> c2 >> l;
                line ip;
                ip.leng = l;
                ip.poi1 = c1-'A';
                ip.poi2 = c2-'A';
                input.push_back(ip);
            }
        }
        int parent[n];
        for(int i=0;i<n;i++)
            parent[i]=i;
        sort(input.begin(),input.end(),sort_func);

        int ans=0;
        for(int i=0;i<input.size();i++)
        {
            int a = ufind( input[i].poi1 , parent);
            int b = ufind( input[i].poi2 , parent);

            if(a != b)
            {
                ans += input[i].leng;
                parent[a] = b;
            }
        }
        cout << ans << "\n";
    }
}

