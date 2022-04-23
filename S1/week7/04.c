#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int left,right,key;
    scanf("%d%d%d",&left,&right,&key);
    int n2=right-left+1;
    int new_a[n2];

    int at_left=0,at_right=n2-1;
    int same_as_key=0;
    for(int i=left;i<=right;i++)
    {
        if(a[i]<a[key])
        {
            new_a[at_left]=a[i];
            at_left++;
        }
        else if(a[i]>a[key])
        {
            new_a[at_right]=a[i];
            at_right--;
        }
        else if (a[i]==a[key])
            same_as_key++;
    }
    for(int i=0;i<same_as_key;i++)
    {
        new_a[at_right]=a[key];
        at_right--;
    }


    for(int i=0;i<n;i++)
    {
        if(i<left||i>right)
            printf("%d ",a[i]);
        else
            printf("%d ",new_a[i-left]);
    }

    return 0;
}

