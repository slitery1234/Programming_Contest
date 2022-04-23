#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int binary_search(int target,int a[],int n)
{
    int left = 0,right = n-1;
    int k = 0;
    while(left <= right)
    {
        k = (left+right)/2;

        if(target < a[k])
            right = k-1;
        else if(target > a[k])
            left = k+1;
        else if(target == a[k])
            break;
    }

    while(target > a[k] && k<n)
        k++;
    while(target < a[k] && k>=0)
        k--;

    return k;
}

int main()
{
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    int x1[n1],x2[n2+1];

    for(int i=0;i<n1;i++)
        scanf("%d",&x1[i]);
    for(int i=0;i<n2;i++)
        scanf("%d",&x2[i+1]);
    x2[0]=-1;
    quick_sort(x2,n2+1);
/*
    for(int i=0;i<n2+1;i++)
        printf("%d %d\n",i,x2[i]);
*/
    int l,r;
    scanf("%d%d",&l,&r);
//^INPUT
//---------------------------------------------

    int index;
    int left_l,left_r;
    int right_l,right_r;

    for(int i=0;i<n1;i++)
    {
        index = x1[i];
        left_l = index-r-1;
        left_r = index-l;
        right_l = index+l-1;
        right_r = index+r;

        left_l = binary_search(left_l,x2,n2+1);
        left_r = binary_search(left_r,x2,n2+1);
        right_l = binary_search(right_l,x2,n2+1);
        right_r = binary_search(right_r,x2,n2+1);

        if(left_l < 0)
            left_l = 0;
        if(left_r < 0)
            left_r = 0;
        if(right_l < 0)
            right_l = 0;
        if(right_r < 0)
            right_r = 0;


        printf("\n%d %d",index,left_r-left_l+right_r-right_l);
    }


    return 0;
}
/*
2 10
6 4
1 2 3 4 5 6 7 8 9 10
2 3
*/
