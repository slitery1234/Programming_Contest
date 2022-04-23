#include <bits/stdc++.h>
using namespace std;

vector<long long int> ans1,ans2;
vector<int> v1,v2;
long long int INF = 1e18;

int listans1(int l,int r,long long int value)
{
    ans1.push_back(value);
    for(int i=l;i<r;i++)
    {
        if(INF / value >= v1[i])
            listans1(i,r,value*v1[i]);
    }
}
int listans2(int l,int r,long long int value)
{
    ans2.push_back(value);
    for(int i=l;i<r;i++)
    {
        if(INF / value >= v2[i])
            listans2(i,r,value*v2[i]);
    }
}
long long int findans(long long int m)
{
    long long int rtn = 0;
    for(int i=0;i<ans1.size();i++)
    {
        rtn += (upper_bound(ans2.begin(),ans2.end(),m/ans1[i]) - ans2.begin());
    }
    return rtn;
}

int main()
{
    int n;
    scanf("%d",&n);
    int ip;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ip);
        if(i%2 == 0)
            v1.push_back(ip);
        else
            v2.push_back(ip);
    }
    listans1(0,v1.size(),1);
    listans2(0,v2.size(),1);
    sort(ans1.begin(),ans1.end());
    sort(ans2.begin(),ans2.end());
    long long int k;
    scanf("%lld",&k);

    long long int l=1,r=INF,mid;
    long long int ans;
    while(l<=r)
    {
        mid = (l+r)/2;
        long long int fs = findans(mid);
        if(fs >= k)
        {
            r=mid-1;
            ans = mid;
        }
        else
            l=mid+1;
    }

    printf("%lld\n",ans);

    return 0;
}
