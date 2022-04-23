#include <stdio.h>
#include <stdlib.h>


int binary_search ( int A[], int n, int k )
{
    int left=0,right=(n-1);
    int mid=(left+right)/2;


    while(left<right||left==right)
    {
        if(k==A[mid])
            return 1;
        else if(k>A[mid])
        {
            left=mid+1;
            mid=(left+right)/2;
        }
        else if(k<A[mid])
        {
            right=mid-1;
            mid=(left+right)/2;
        }
    }

    return 0;
}
