#include <stdio.h>
#include <math.h>
int main()
{
    int nc;
    scanf("%d",&nc);
    long long int pre[50000];
    for(int i=0;i<40000;i++)
    {
        pre[i] = (1+i)*i/2;
        if(i >= 10)
            pre[i] += (i-8)*(i-9)/2;
        if(i >= 100)
            pre[i] += (i-98)*(i-99)/2;
        if(i >= 1000)
            pre[i] += (i-998)*(i-999)/2;
        if(i >= 10000)
            pre[i] += (i-9998)*(i-9999)/2;
    }

    for(int ni=0; ni<nc; ni++)
    {
        long long int n;
        scanf("%lld",&n);
        int x=0;
        for(int i=0;i<100000;i++)
        {
            if(n <= pre[i])
            {
                n-=pre[i-1];
                x=i;
                break;
            }
        }
        for(int i=1;i<=x;i++)
        {
            int ti = i;
            int digit = 1;
            while(ti/10)
            {
                digit ++;
                ti /=10;
            }

            if(n > digit)
                n-=digit;
            else
            {
                ti = i;
                int arr[digit];
                for(int d=digit-1;d>=0;d--)
                {
                    arr[d] = ti%10;
                    ti /= 10;
                }
                printf("%d\n",arr[n-1]);
                break;
            }

        }
    }

}
/*
1 2 3 4 5 6 7 8 9
10+1 11+2 12+3 13+4 14+5 15+6 16+7 17+8 18+9 19+10
20+11 21+12 ~99+90
100+91+1 101+92+2 102+93+3 ~999+990+90

(1+n)*n/2
(1+n)*n/2 + (1+n-9)*(n-9)/2
(1+n)*n/2 + (1+n-9)*(n-9)/2 + (1+n-99)*(n-99)/2
*/
