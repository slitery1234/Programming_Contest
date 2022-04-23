#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition_by_key (int A[], int left, int right, int key )
{
    int n=right-left+1;

    int new_A[n];
    int at_left=0,at_right=n-1;
    int same_as_key=0;
    for(int i=left; i<=right; i++)
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


    for(int i=0; i<same_as_key; i++)
    {
        new_A[at_right]=A[key];
        at_right--;
    }

    for(int i=0; i<n; i++)
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
    int n,c;
    scanf("%d",&n);
    int coin[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&coin[i]);
    }
    scanf("%d",&c);
    quick_sort(coin,n);

    int coins[c+1];

    for(int i=0;i<=c;i++)
    {
        coins[i] = c+1;     //always larger when coin >= 1 && c = c
    }
    coins[0]=0;

    for(int i=0;i<n;i++)
    {
        for(int j=coin[i];j<=c;j++)
        {
            if(coins[j] <= coins[j-coin[i]] +1)  //If put the coin in won't better
            {
                coins[j] = coins[j];
            }
            else                                //If put in will better
            {
                coins[j] = coins[j-coin[i]] +1;
            }
        }
    }

    if(coins[c] == c+1)      //If can't recah the c num
        printf("-1");
    else
        printf("%d",coins[c]);

    return 0;
}
