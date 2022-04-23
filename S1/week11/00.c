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
/*
int main()
{
    int n=3,m=5;
    int A[3]={1,2,3};
    int B[5]={1,3,5,7,9};
    int C[n+m];
    merge_sorted_arrays (A,n,B,m,C);
    for(int i=0;i<m+n;i++)
        printf("%d,",C[i]);
}*/
