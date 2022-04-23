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
long long int binary_search(int x[],int n,long long int k)
{
    long long int left = 0,right = n;
    long long int index = (left + right) /2;

    while(left < right)
    {
        index = (left + right) /2;

        if(x[index] < k)
        {
            left = index + 1;
        }
        else if(x[index] == k)
        {
            return index + 1;
        }
        else if(x[index] > k)
        {
            right = index;
        }
    }

    if(index == 0)
    {
        if(x[0] > k)
            return 0;
        else
            return 1;
    }
    return index+1;
}


int main()
{
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    int x1[n1],x2[n2];

    for(int i=0;i<n1;i++)
        scanf("%d",&x1[i]);
    for(int i=0;i<n2;i++)
        scanf("%d",&x2[i]);

    quick_sort(x2,n2);

    int l,r;
    scanf("%d%d",&l,&r);
//^INPUT
//---------------------------------------------
    long long int two_l=0,two_r=0;
    long long int two_ll=0,two_lr=0;
    long long int two_rl=0,two_rr=0;

    for(int i=0;i<n1;i++)
    {
        long long int ll = x1[i]-r-1;
        if(ll < 0)
            ll = 0;
        long long int lr = x1[i]-l;
        if(lr < 0)
            lr = 0;

        long long int rl = x1[i]+l-1;
        long long int rr = x1[i]+r;

        //printf("\n%d %d %d %d\n",ll,lr,rl,rr);
        two_ll = binary_search(x2,n2,ll);
        two_lr = binary_search(x2,n2,lr);
        two_rl = binary_search(x2,n2,rl);
        two_rr = binary_search(x2,n2,rr);
        //printf("%d %d %d %d\n",two_ll,two_lr,two_rl,two_rr);


        two_l = two_lr - two_ll;
        two_r = two_rr - two_rl;

        printf("%d %lld \n",x1[i],two_l+two_r);
    }
    return 0;
}
/*
2 10
6 4
1 2 3 4 5 6 7 8 9 10
2 3
*/
