#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);

    int a[n],b[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            if(a[i]<a[j])
            {
                if(b[j]<b[i]+1)
                    b[j]=b[i]+1;
            }
    }
    int max_length=0;
    for(int i=0;i<n;i++)
    {
        if(max_length<b[i])
            max_length=b[i];
    }
    printf("%d",max_length);

}
