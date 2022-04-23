#include <bits/stdc++.h>
using namespace std;
int main()
{
    double r;
    double p;
    int n;
    scanf("%lf%d%lf",&r,&n,&p);
    r = r+1;
    double ans=0;
    for(int i=1;i<=n;i++)
    {
        ans = ans + (p * pow(r,i));
    }
    printf("%d",(int)ans);
    return 0;
}
