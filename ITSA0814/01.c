#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],b,c[n],d[n];
    for(int i=0; i<n; i++)
    {
        d[i]=i;
        a[i]=0;
        scanf("%d",&c[i]);
        b=c[i];
        while(b!=0)
        {
            a[i] += (b%10);
            b = b/10;
        }
    }

    int compare(const void *e, const void *f)
    {
        int g = a[*(int *)e];
        int h = a[*(int *)f];
        if(g < h)
            return -1;
        else if (g == h)
        {
            g=c[*(int *)e];
            h=c[*(int *)f];
            if(g < h)
                return -1;
            else
                return 1;

        }
        else
            return 1;
    }

    qsort(d,n,sizeof(int),compare);

    for(int i=0; i<n-1; i++)
    {
        printf("%d ",c[d[i]]);
    }
    printf("%d\n",c[d[n-1]]);

    return 0;
}
