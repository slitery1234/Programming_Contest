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
    int a[n];
    int odd[n],even[n];
    int odd_num=0,even_num=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]%2==1)
        {
            odd[odd_num]=a[i];
            odd_num++;
        }
        else
        {
            even[even_num]=a[i];
            even_num++;
        }
    }

    quick_sort(odd,odd_num);
    quick_sort(even,even_num);

    int x;
    int ans=0;
    if(odd_num>even_num)
    {
        x=odd_num-even_num;
        if(x>1)
        {
            x--;
            for(int i=0;i<x;i++)
                ans+=odd[i];
            printf("%d",ans);
        }
        else
            printf("0");
    }
    else
    {
        x=even_num-odd_num;
        if(x>1)
        {
            x--;
            for(int i=0;i<x;i++)
                ans+=even[i];
            printf("%d",ans);
        }
        else
            printf("0");
    }



    return 0;
}
