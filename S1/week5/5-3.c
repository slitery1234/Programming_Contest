#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[200000];
    int x,y,temp;
    int amax=0;
    for(int i=0;i<200000;i++)
        a[i]=0;

    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        if(x>y)
        {
            temp=x;
            x=y;
            y-temp;
        }
        for(int j=x;j<y;j++)
            a[100000+j]+=1;

    }
    for(int i=0;i<200000;i++)
    {
        if(a[i]>amax)
            amax=a[i];
    }



    printf("%d",amax);


    return 0;
}
