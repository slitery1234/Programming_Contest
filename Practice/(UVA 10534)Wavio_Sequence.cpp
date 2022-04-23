#include <bits/stdc++.h>
using namespace std;

int n;
int ip[10040];
int LISleng[10040];
int LDSleng[10040];

void LIS()
{
    vector<int> v;
    v.push_back(ip[0]);
    LISleng[0] = 1;
    for(int i=1;i<n;i++)
    {
        if(ip[i] > v.back())
            v.push_back(ip[i]);
        else
        {
            int index = lower_bound(v.begin(),v.end(),ip[i]) - v.begin();
            v[index] = ip[i];
        }
        LISleng[i] = v.size();
    }
    return;
}
void LDS()
{

}
int main()
{
    while(scanf("%d",&n) != EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&ip[i]);
        LIS();
        LDS();
        for(int i=0;i<n;i++)
            printf("%d ",LISleng[i]);
        printf("\n");
        for(int i=0;i<n;i++)
            printf("%d ",LDSleng[i]);
    }

}
