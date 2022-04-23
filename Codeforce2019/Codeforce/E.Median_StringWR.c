#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//void recursive_quick_sort (int[],int,int);

int partition_by_key (int A[], int left, int right, int key )
{
    int n=right-left+1;

    int new_A[n];
    int at_left=0,at_right=n-1;
    int same_as_key=0;
    for(int i=left;i<=right;i++)
    {
        if(A[i]<A[key])
        {
            new_A[at_left]=A[i];
            at_left++;
        }
        else if(A[i]>A[key])
        {
            new_A[at_right]=A[i];
            at_right--;
        }
        else if (A[i]==A[key])
            same_as_key++;
    }


    for(int i=0;i<same_as_key;i++)
    {
        new_A[at_right]=A[key];
        at_right--;
    }

    for(int i=0;i<n;i++)
        A[i+left]=new_A[i];

    return left+at_left;
}

void recursive_quick_sort (int A[],int left,int right)
{
    int key;
    srand((unsigned)time(NULL));


    if(left>right)
        return;
    else
    {
        key=( rand() % (right-left+1) );
        key = partition_by_key (A,left,right,left+key);
        recursive_quick_sort (A,left,key-1);
        recursive_quick_sort (A,key+1,right);
    }


    return;
}
void quick_sort (int A[],int n)
{
    recursive_quick_sort(A,0,n-1);
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    char c[n],c2[n];
    int ci[n],cimax=0;
    char ans[n];

    for(int i=0;i<n;i++)
    {
        scanf("%c",&c[i]);
        if(c[i]=='\n')
            scanf("%c",&c[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%c",&c2[i]);
        if(c2[i]=='\n')
            scanf("%c",&c2[i]);
    }

    for(int i=0;i<n;i++)
    {
        ci[i]=((int)c2[i]-(int)c[i]);
        printf("%d ",ci[i]);
        if(ci[i]<0)
        {
            ci[i]+=26;
            if( ( c[i]+(ci[i]+1)/2) > 'z')
                ans[i]=(c[i]+(ci[i]+1)/2)-26;
            else
                ans[i]=(c[i]+(ci[i]+1)/2)-1;
        }
        else if(ci[i]==0)
            ans[i]=c[i];
        else if(ci[i]==1)
            ans[i]=c2[i];
        else
            ans[i]=c[i]+((ci[i]+1)/2)-1;
    }



    for(int i=0;i<n;i++)
    {
        printf("%c",ans[i]);
    }





    return 0;
}
