#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    int length[n];
    int max_len=0,max_i=0;

    for(int i=0;i<n;i++)
        length[i]=1;

    for(int i=n-1;i>=0;i--)
    {
        max_i=0;
        max_len=0;
        for(int j=n-1;j>i;j--)
        {
            if(a[i]<a[j])
            {
                if(max_len < length[j])
                {
                    max_len=length[j];
                    max_i=j;
                }
            }
        }
        length[i]=length[i]+max_len;
    }
    //--------------------------

    max_i=0;
    max_len=0;

    for(int i=0;i<n;i++)
    {
        if(max_len < length[i])
        {
            max_len=length[i];
            max_i=i;
        }
    }
    int t=max_len;
    for(int i=0;i<n;i++)
    {
        if(length[i]==t)
        {
            printf("%d ",a[i]);
            t--;
        }
    }

}
