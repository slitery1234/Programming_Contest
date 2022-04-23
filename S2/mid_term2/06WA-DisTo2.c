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


int binary_searchEX ( int A[], int n, int l_index, int r_index)
{
    int left=0,right=(n-1);
    int l_mid=(left+right)/2;
    int r_mid=(left+right)/2;
    int l_found=0;

    while(left<=right)
    {
        l_mid=(left+right)/2;
        if(l_index==A[l_mid])
        {
            l_found = 1;
            break;
        }
        else if(l_index>A[l_mid])
        {
            left=l_mid+1;
        }
        else if(l_index<A[l_mid])
        {
            right=l_mid-1;
        }
    }

    left=0;
    right=(n-1);

    while(left<=right)
    {
        if(r_index==A[r_mid])
        {
            break;
        }
        else if(r_index>A[r_mid])
        {
            left=r_mid+1;
        }
        else if(r_index<A[r_mid])
        {
            right=r_mid-1;
        }
        r_mid=(left+right)/2;
    }

    //printf("%d: %d\n",l_index,l_mid);
    //printf("%d: %d\n",r_index,r_mid);
    if(l_found == 1)
        return r_mid-l_mid+1;
    else
        return r_mid-l_mid;
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

    int two_l=0,two_r=0;

    for(int i=0;i<n1;i++)
    {

        two_l = binary_searchEX(x2,n2,x1[i]-r,x1[i]-l);
        two_r = binary_searchEX(x2,n2,x1[i]+l,x1[i]+r);

        //printf("** %d - %d\n",two_l,two_r);

        printf("%d %d \n",x1[i],two_l+two_r);
    }
    return 0;
}
/*
2 10
6 4
1 2 3 4 5 6 7 8 9 10
2 3
*/
