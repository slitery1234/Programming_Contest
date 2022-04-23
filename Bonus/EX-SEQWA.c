#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[4]={6,-8,7,-42};
    int n = 4;

    int res =0;
    int cur =0;
    int k=-1;

    for(int i=0;i<n;i++)
    {
        cur = cur + a[i];
        if(cur < 0)
        {
            cur = 0;
            k = i;
        }
        if(res>(i-k)*cur)
        {
            res = res;
        }
        else
        {
            res = (i-k)*cur;
        }
    }
    printf("%d",res);

    return 0;
}
