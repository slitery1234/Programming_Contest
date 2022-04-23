#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    int L;
    scanf("%d %d",&n,&L);
    int a[n];
    int total[n];
    int last_i=0,now_i=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(i==0)
            total[i]=a[i];
        else
            total[i]=a[i]+total[i-1];
    }
/*
    for(int i=0;i<n;i++)
    {
        printf("%d ",total[i]);
    }

    printf("\n");
*/
    for(int i=0;i<n;i++)
    {
        if( total[i] >= L)
        {
            while(total[i] - total[last_i] >= L )
                    last_i++;
            printf("%d ",last_i+1);
        }
        else
            printf("-1 ");
    }


    return 0;
}
