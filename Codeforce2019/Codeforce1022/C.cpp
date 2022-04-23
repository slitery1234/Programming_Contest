#include <bits/stdc++.h>
using namespace std;

long long int va[300000],vb[300000],vc[20000];
long long int x[40];
long long int a[20],b[20],c[5];

int listva()
{
    int k=1;
    va[0] = a[0];
    for(int i=1; i<18; i++)
    {
        for(int j=0; j<k; j++)
        {
            va[k+j] = (a[i]+va[j]);
        }
        va[2*k] = a[i];
        k*=2;
        k++;
    }
    return k;
}
int listvb()
{
    int k=1;
    vb[0] = b[0];
    for(int i=1; i<18; i++)
    {
        for(int j=0; j<k; j++)
        {
            vb[k+j] = (b[i]+vb[j]);
        }
        vb[2*k] = b[i];
        k*=2;
        k++;
    }
    return k;
}
int listvc()
{
    int k=1;
    vc[0] = c[0];
    for(int i=1; i<4; i++)
    {
        for(int j=0; j<k; j++)
        {
            vc[k+j] = (c[i]+vc[j]);
        }
        vc[2*k] = c[i];
        k*=2;
        k++;
    }
    return k;
}

int main()
{

    x[0] = 1;
    for(int i=1; i<40; i++)
        x[i] = x[i-1]*3;
    for(int i=0; i<36; i++)
    {
        if(i % 2 == 0)
            a[i/2] = x[i];
        else
            b[i/2] = x[i];
    }
    for(int i=0; i<4; i++)
        c[i] = x[36+i];

    int siza = listva();
    int sizb = listvb();
    int sizc = listvc();
    va[siza] = 0;
    vb[sizb] = 0;
    vc[sizc] = 0;
    siza++;
    sizb++;
    sizc++;
    sort(va,va+siza);
    sort(vb,vb+sizb);
    sort(vc,vc+sizc);

    int nc;
    scanf("%d",&nc);

    for(int ni=0; ni<nc; ni++)
    {
        long long int n;
        scanf("%lld",&n);
        int tem = 0;
        long long int ic=0;
        ic = lower_bound(vc,vc+sizc,n)-vc;
        long long int minn = x[39];

        for(long long int ii=0; ii<=ic; ii++)
        {
            long long int ia = lower_bound(va,va+siza,n-vc[ii])-va;
            if(ia == siza)
                ia--;
            for(long long int i=0; i<=ia; i++)
            {
                long long int ib = lower_bound(vb,vb+sizb,n-vc[ii]-va[i])-vb;
                if(ib == sizb)
                    ib--;
                if(va[i] + vb[ib] + vc[ii] < minn && va[i] + vb[ib] + vc[ii] >= n)
                    minn = va[i] + vb[ib]+ vc[ii];
            }
        }
        printf("%lld\n",minn);
    }

    return 0;
}
