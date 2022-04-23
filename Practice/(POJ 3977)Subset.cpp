#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long int> ip1,ip2;
vector<pair<long long int, int > > sum1,sum2;
pair<long long int, int> ans;


void ssum1(long long int v)
{
    int t = sum1.size();
    for(int i=0; i<t; i++)
        sum1.push_back(make_pair(sum1[i].first+v,sum1[i].second+1));
    sum1.push_back(make_pair(v,1));
    return;
}
void ssum2(long long int v)
{
    int t = sum2.size();
    for(int i=0; i<t; i++)
        sum2.push_back(make_pair(sum2[i].first+v,sum2[i].second+1));
    sum2.push_back(make_pair(v,1));
    return;
}

void insans(long long int v,int c)
{

    pair<long long int ,int> p = make_pair(v,c);
    if(p < ans)
        ans = p;
    return;
}
long long int aabs(long long int x)
{
    if(x >= 0)
        return x;
    else
        return -1*x;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n != 0)
    {
        ans.first = 1e18;
        ans.second = 0;
        if(n == 1)
        {
            long long int ip;
            scanf("%lld",&ip);
            printf("%lld 1\n",aabs(ip));
        }
        else
        {
            long long int ip;
            for(int i=0; i<n; i++)
            {
                scanf("%lld",&ip);
                if(i%2 == 0)
                    ip1.push_back(ip);
                else
                    ip2.push_back(ip);
            }
            for(int i=0; i<ip1.size(); i++)
                ssum1(ip1[i]);
            for(int i=0; i<ip2.size(); i++)
                ssum2(ip2[i]);

            sort(sum2.begin(),sum2.end());
            int s2z = sum2.size();

            for(int i=0; i<sum1.size(); i++)
            {
                long long int s1 = sum1[i].first;
                int c1 = sum1[i].second;
                insans(aabs(s1),c1);

                int s2i = lower_bound(sum2.begin(),sum2.end(),make_pair(-1*s1,0))-sum2.begin();

                if(s2i != s2z)
                    insans(aabs(s1+sum2[s2i].first),c1+sum2[s2i].second);
                if(s2i != 0)
                    insans(aabs(s1+sum2[s2i-1].first),c1+sum2[s2i-1].second);
                if(s2i < s2z-1)
                    insans(aabs(s1+sum2[s2i+1].first),c1+sum2[s2i+1].second);
            }

            for(int i=0; i<sum2.size(); i++)
                insans(aabs(sum2[i].first),sum2[i].second);

            printf("%lld %d\n",ans.first,ans.second);
        }

        ip1.clear();
        ip2.clear();
        sum1.clear();
        sum2.clear();
        scanf("%d",&n);
    }
    return 0;
}
