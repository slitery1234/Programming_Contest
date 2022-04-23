#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int v[n],v2[n],a[n][n];
    int i=0,j=0;
    int ans=0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
        v2[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            v2[i]+=(v[j]*a[i][j]);
        ans+=v[i]*v2[i];
        //printf("%d\t",v2[i]);

    }

    printf("%d",ans);
    return 0;
}
