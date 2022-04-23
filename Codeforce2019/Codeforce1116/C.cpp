#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    long long int b[n];
    b[0] = a[0];

    for(int i=1;i<m;i++)
        b[i] = b[i-1] + a[i];
    for(int i=m;i<n;i++)
        b[i] = b[i-1] + a[i] - a[i-m];

    for(int i=m;i<n;i++)
        b[i] = b[i-m] + b[i];
    for(int i=m;i<n;i++)
        b[i] = b[i-m] + b[i];

    for(int i=0;i<n;i++)
        printf("%lld ",b[i]);
    printf("\n");

    return 0;
}
/*
2 3 4 4 6 6 7 8 19
2 5 7 8 10 12 13 15 27
2 5 9 13 19 25 32 40 67
2 5 11 18 30 43 62 83 121

m = 3
1 2 3 4 5 6 7
1 3 6 9 12 15 18
1 3 6 10 15 21 28
1 3 6 11 18 27 39


2 3 4 4 6

2 5 9 11 14
2 5 9 13 19
2 5 9 15 24


*/
