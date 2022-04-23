#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],b[n];
    int t1=-1,t2=-1,tmin=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);

    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]>=a[j]&&a[i]<=b[j])
                t1+=1;
            if(b[i]>=a[j]&&b[i]<=b[j])
                t2+=1;
        }

        if(t1>tmin)
            tmin=t1;
        if(t2>tmin)
            tmin=t2;
        t1=-1;
        t2=-1;
    }
    printf("%d",tmin);


    return 0;
}
