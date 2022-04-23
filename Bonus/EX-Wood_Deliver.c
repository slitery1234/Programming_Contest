#include <stdio.h>
#include <stdlib.h>

long long int test(long long int input,long long int wood[],int n,int m)
{
    long long int x = 0;
    long long int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += wood[i];
        if(sum > input)
        {
            x++;
            sum = wood[i];
        }
    }

    if(x < m)
        return 1;
    else
        return 0;
}

long long int binary_search(long long int left,long long int right ,long long int wood[] ,int n,int m)
{
    if( test(left,wood,n,m) == 1 )
        return left;

    if( test(right,wood,n,m) == 0 )
        return -1;

    int mid;

    while( left < right - 1 )
    {
        mid = ( left + right ) / 2;

        if( test(mid,wood,n,m) == 0 )
            left = mid;
        else
            right = mid;
    }

    return right;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    long long int wood[n];

    for(int i=0;i<n;i++)
        scanf("%lld",&wood[i]);

    long long int wood_sum=0;


    for(int i=0;i<n;i++)
        wood_sum += wood[i];

    printf("%lld\n",binary_search( 1, wood_sum+1 ,wood ,n,m ) );



    return 0;
}

