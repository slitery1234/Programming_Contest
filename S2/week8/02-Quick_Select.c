#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int quick_select(int a[],int k,int n)
{
    srand(time(NULL));
    int index=rand()%n;
    int lesser[n],same[n],great[n];
    int len_l=0,len_s=0,len_g=0;


    for(int i=0; i<n; i++)
    {
        if(a[i] > a[index])
        {
            great[len_g]=a[i];
            len_g++;
        }
        else if(a[i] == a[index])
        {
            same[len_s]=a[i];
            len_s++;
        }
        else
        {
            lesser[len_l]=a[i];
            len_l++;
        }
    }



/*
    for(int i=0; i<len_l; i++)
    {
        printf("%d ",lesser[i]);
    }
    printf("\n");
    for(int i=0; i<len_s; i++)
    {
        printf("%d ",same[i]);
    }
    printf("\n");
    for(int i=0; i<len_g; i++)
    {
        printf("%d ",great[i]);
    }
    printf("\n%d,%d\n",len_l,len_g);
*/
    if(k < len_l)
        return quick_select(lesser,k,len_l);
    else if(k < len_l+len_s)
        return same[0];
    else
        return quick_select(great,k-len_l-len_s,len_g);
}



int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    int index;
    scanf("%d",&index);

    int ans = quick_select(a,index-1,n);
    printf("%d\n",ans);

    /*
    for(int i=0;i<len_l;i++)
    {
        printf("%d ",lesser[i]);
    }
    printf("\n");
    for(int i=0;i<len_g;i++)
    {
        printf("%d ",great[i]);
    }
    printf("\n%d",len_l);
    */



    return 0;
}
