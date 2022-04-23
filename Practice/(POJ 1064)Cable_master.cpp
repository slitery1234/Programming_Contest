//https://vjudge.net/problem/17529/origin

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;

int n,k;

int cut(int a[],int input)
{
    if(input == 0)
        return 1;

    int cou=0;
    int b[n];
    for(int i=0;i<n;i++)
    {
        b[i] = a[i];
        while(b[i] - input >=0)
        {
            b[i]-=input;
            cou++;
        }
    }
    if(cou >= k)
        return 1;
    else
        return 0;
}
int binary_cut(double a[],double m)
{
    int l,r,mid;
    l = 0;
    r = m*100;
    mid = (l + r)/2;
    int b[n];
    for(int i=0;i<n;i++)
        b[i] = a[i] * 100;

    while(l <= r)
    {
        if( cut(b,mid) )
            l = mid+1;
        else
            r = mid-1;
        mid = (l + r)/2;
    }
    return mid;
}

int main()
{
    scanf("%d%d",&n,&k);
    double a[n];
    double maxx=0;
    int ans=0;

    for(int i=0;i<n;i++)
    {
        scanf("%lf",&a[i]);
        maxx = max(maxx,a[i]);
    }

    ans = binary_cut(a,maxx);
    printf("%d.%02d\n",ans/100,ans%100);
    return 0;
}
