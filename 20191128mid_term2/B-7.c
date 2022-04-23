/* probID: MT2-B-7-InPlacePartition*/
#include <stdio.h>

void swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int In_Place_Partition(int a[],int left,int right,int key)
{
    if(left == right)
        return left;

    int l=left+1,r=right;
    int tmp = a[key];
    swap(&a[key],&a[left]);
    while(l<r)
    {
        while(a[r]>=tmp && l<r)
            r--;
        while(a[l]<tmp && l<r)
            l++;
        if(l<r)
            swap(&a[l],&a[r]);
    }

    if(a[l] > tmp)
    {
        swap(&a[l-1],&a[left]);
        return l-1;
    }
    else
    {
        swap(&a[l],&a[left]);
        return l;
    }
}
/*
int A[10000000], n;
int left, right, key;

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&A[i]);
    scanf("%d%d%d",&left,&right,&key);
    key = In_Place_Partition(A, left, right, key);
    for(int i=0; i<n; i++)
        printf("%d ",A[i]);
    printf("\n%d\n", key);
}
*/
