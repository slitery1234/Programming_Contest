#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int x;
    int c[n];
    scanf("%d",&x);

    for(int i=n-1;i>=0;i--)
    {
        c[i]=x%10;
        x/=10;
    }

    int a[10];
    for(int i=1;i<=9;i++)
    {
        scanf("%d",&a[i]);
    }

    int i=0;
    int has_change=0;
    for(i=0;i<n;i++)
    {
        if(c[i] <= a[c[i]])
        {
            printf("%d",a[c[i]]);
            has_change = 1;
        }
        else if(has_change==1)
        {
            break;
        }
        else
            printf("%d",c[i]);
    }

    for(i=i;i<n;i++)
    {
        printf("%d",c[i]);
    }

    return 0;
}
