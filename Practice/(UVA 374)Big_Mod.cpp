#include<bits/stdc++.h>
using namespace std;

long long int ans(long long int b,long long int p,long long int m)
{
    if(p == 0)
        return 1;
    else if(p == 1)
        return b%m;
    else if(p%2 == 0)
        return (ans(b,p/2,m) * ans(b,p/2,m)) % m;
    else if(p%2 == 1)
        return (ans(b,p/2,m) * ans(b,p/2,m) * b) % m;
}

int main()
{
    long long int b,p,m;

    while(scanf("%lld%lld%lld",&b,&p,&m) != EOF)
    {
        printf("%lld\n",ans(b,p,m));
    }

    return 0;
}
