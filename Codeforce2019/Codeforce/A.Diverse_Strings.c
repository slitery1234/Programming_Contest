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
    char a[100];
    int j=0;


    for(int i=0;i<n+1;i++)
    {
        j=0;
        scanf("%c",&a[j]);
        while(a[j]!='\n')
        {
            j++;
            scanf("%c",&a[j]);
        }
        int ai[j];
        for(int k=0;k<j;k++)
            ai[k]=(int)a[k];


        quick_sort(ai,j);
        int ans=0;


        for(int k=0;k<j-1;k++)
        {
            if(ai[k+1]-ai[k]!=1)
                ans=1;
        }

        if(i==0)
        {

        }
        else if(ans==0)
            printf("Yes\n");
        else
            printf("No\n");
    }



    return 0;
}
