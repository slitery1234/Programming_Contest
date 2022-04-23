#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
long long int gcd ( long long int a, long long int b )
{
    if(b==0)
        return a;
    else if(a<b)
        return gcd (b,a);
    else
    {
        a=a%b;
        return gcd (b,a);
    }
}

long long int partition_by_key (long long int A[], int left, int right, int key )
{
    int n=right-left+1;

    long long int new_A[n];
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

void recursive_quick_sort (long long int A[],int left,int right)
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
void quick_sort (long long int A[],int n)
{
    recursive_quick_sort(A,0,n-1);
    return;
}

long long int gcd_parade ( long long int a[], int n )
{
    long long int k;
    while(n!=1)
    {
        for(int i=0;i<n-1;i++)
        {
            k=gcd(a[i],a[i+1]);
            a[i]=k;
        }
        n--;
    }
    return a[0];
}

int main()
{

    int n=0;
    scanf("%d",&n);

    char message[50];
    long long int parade[8];
    long long int n_parade[40];

    if(n<=8)
    {
        for(int i=0;i<n;i++)
        {
            printf("? %d\n",i+1);
            fflush(stdout);
            scanf("%lld",&parade[i]);
        }
        quick_sort(parade,n);
        printf("! %lld\n", (parade[1]-(parade[0])) );
        fflush(stdout);
    }
    else
    {
        for(int i=0;i<8;i++)
        {
            printf("? %d\n",(rand()%n)+1);
            fflush(stdout);
            scanf("%lld",&parade[i]);
        }

        quick_sort(parade,8);

        int k=0;
        for(int i=0;i<7;i++)
        {
            for(int j=7;j>i;j--)
            {
                n_parade[k] = parade[j] - parade[i];
                k++;
            }
        }

        gcd_parade(n_parade,7);
        printf("! %lld\n",n_parade[0]);
        fflush(stdout);
    }

    scanf("%s",message);


    return 0;
}
