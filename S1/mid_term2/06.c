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

void recursive_merge_sort (int A[],int left,int right,int temp[])
{
    if(left > right)
        return;
    else
    {
        int mid=(left+right)/2;
        if(mid!=left&&mid!=right)
        {
            recursive_merge_sort(A,left,mid,temp);
        }
        recursive_merge_sort(A,mid+1,right,temp);
        merge_sorted_arrays(&A[left],mid-left+1,&A[mid+1],right-mid,temp);
        for(int i=left;i<=right;i++)
            A[i]=temp[i-left];
        return;

    }
}

void merge_sort (int A[],int n)
{
    int temp[n];
    recursive_merge_sort(A,0,n-1,temp);
    return;
}/*
int main()
{
    int A[8]={1,8,1,2,1,3,5,4};
    merge_sort (A,8);
    for(int i=0;i<8;i++)
        printf("%d ",A[i]);
}
*/
