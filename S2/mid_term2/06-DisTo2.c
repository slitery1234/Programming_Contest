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


int binary_search ( int A[], int n, int k)
{
    int left=0,right=(n-1);
    int mid=(left+right)/2;


    while(left<=right)
    {
        if(k==A[mid])
        {
            return mid;
        }
        else if(k>A[mid])
        {
            left=mid+1;
        }
        else if(k<A[mid])
        {
            right=mid-1;
        }
        mid=(left+right)/2;
    }

    return mid;
}


int main()
{
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    int x1[n1],x2[n2+1];
    x2[0]=-1;
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&x1[i]);
    }
    for(int i=1;i<n2+1;i++)
    {
        scanf("%d",&x2[i]);
    }

    quick_sort(x2,n2+1);

    int l,r;
    scanf("%d%d",&l,&r);

    int right_bound,left_bound;
    int two_can_reach,two_can_see;


    for(int i=0;i<n1;i++)
    {
        right_bound = binary_search(x2,n2+1,x1[i]+r);
        left_bound = binary_search(x2,n2+1,x1[i]-r-1);
        two_can_reach = right_bound-left_bound;

        right_bound = binary_search(x2,n2+1,x1[i]+l-1);
        left_bound = binary_search(x2,n2+1,x1[i]-l);
        two_can_see = right_bound-left_bound;

        printf("%d %d\n",x1[i],two_can_reach-two_can_see);
    }
    return 0;
}
