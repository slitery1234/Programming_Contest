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
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int increase[n],decrease[n];
    int increase_num=0,decrease_num=0;

    int temp_i=0;
    int times[300000];
    int has_ans=1;

    for(int i=0;i<300000;i++)
        times[i]=0;

    for(int i=0;i<n;i++)
        times[a[i]]++;

    for(int i=0;i<300000;i++)
    {
        if(times[i]==1)
        {
            increase[increase_num]=i;
            increase_num++;
        }
        else if(times[i]==2)
        {
            increase[increase_num]=i;
            increase_num++;
            decrease[decrease_num]=i;
            decrease_num++;
        }
        else if(times[i]==0)
        {

        }
        else
            has_ans=0;
    }

    if(has_ans==1)
    {
        printf("YES\n");
        printf("%d\n",increase_num);
        for(int i=0;i<increase_num;i++)
            printf("%d ",increase[i]);
        printf("\n");
        printf("%d\n",decrease_num);
        for(int i=decrease_num-1;i>=0;i--)
            printf("%d ",decrease[i]);
    }
    else
    {
        printf("NO");
    }


    return 0;
}
