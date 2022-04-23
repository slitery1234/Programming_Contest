#include <stdio.h>
#include <stdlib.h>

void merge_sorted_arrays ( int A[], int n, int B[], int m, int C[] )
{
    int i=0,j=0;
    int t=0;
    while(t<m+n)
    {
        if(i<n&&j<m)
        {
            if(A[i]<B[j] || A[i]==B[j])
            {
                C[i+j]=A[i];
                i++;
            }
            else if(B[j]<A[i])
            {
                C[i+j]=B[j];
                j++;
            }
        }
        else if(i==n)
        {
            C[i+j]=B[j];
            j++;
        }
        else if(j==m)
        {
            C[i+j]=A[i];
            i++;
        }

        t++;
    }
}
