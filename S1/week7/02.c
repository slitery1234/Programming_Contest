#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    int input;
    int found=0;
    int left=0,right=n;
    int mid=(left+right)/2;

    while(scanf("%d",&input)!=EOF)
    {
        while (left<=right)
        {
            if(input<a[mid])
            {
                right=mid-1;
                mid=(left+right)/2;
            }
            else if(input>a[mid])
            {
                left=mid+1;
                mid=(left+right)/2;
            }
            else if(input==a[mid])
            {
                printf("Found!\n");
                found=1;
                break;
            }
            //printf("%d-%d,a[%d]=%d",left,right,mid,a[mid]);
        }
        if(found==0)
            printf("not found\n");
        mid=(left+right)/2;
        left=0;
        right=n;
        found=0;
    }


    return 0;
}
