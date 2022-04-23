#include<bits/stdc++.h>
using namespace std;

unsigned long long mod_it(unsigned long long b,unsigned long long p,unsigned long long m)
{
    if(p == 0)
        return 1;
    else if(p == 1)
        return b%m;
    else if(p%2 == 0)
        return (mod_it(b,p/2,m) * mod_it(b,p/2,m)) % m;
    else if(p%2 == 1)
        return (mod_it(b,p/2,m) * mod_it(b,p/2,m) * b) % m;
}

int fib[100000];

int main()
{
    int n;
    unsigned long long b,p,m;
    scanf("%d",&n);

    fib[0]=0;
    fib[1]=1;
    set<int> rep;
    int k=0;
    int i;
    for(i=2;i<=100000;i++)
    {
        fib[i] = fib[i-1]%999 + fib[i-2]%999;
        fib[i] = fib[i] %999;
        if(rep.count(fib[i]) == 0)
            rep.insert(fib[i]);
        else
            k++;
        if(k > 999)
            break;
    }
    printf("%d",i);

    for(int i=0;i<n;i++)
    {

    }


    return 0;
}
