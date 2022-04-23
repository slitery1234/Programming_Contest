#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],odd[n],even[n];
    int odd_count=0,even_count=0;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(int i=0;i<n;i++)
    {
        if(a[i]%2!=0)
        {
            odd[odd_count]=a[i];
            odd_count+=1;
        }
        else
        {
            even[even_count]=a[i];
            even_count+=1;
        }
    }

    for(int i=0;i<odd_count;i++)
        printf("%d ",odd[i]);
    printf("\n");
    for(int i=0;i<even_count;i++)
        printf("%d ",even[i]);

    return 0;
}
