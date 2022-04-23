#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    int rec[n][m];
    int sum_by_row[n][m+1];
    int temp_sum=0;
    for(int i=0;i<n;i++)
    {
        sum_by_row[i][0] = 0;
        temp_sum=0;
        for(int j=0;j<m;j++)
        {
            scanf("%d",&rec[i][j]);
            temp_sum += rec[i][j];
            sum_by_row[i][j+1] = temp_sum;
        }
    }

    int r1,r2,c1,c2;
    int n_test;
    scanf("%d",&n_test);

    long int sum=0;
    for(int i=0;i<n_test;i++)
    {
        sum=0;
        scanf("%d %d %d %d",&r1,&r2,&c1,&c2);
        for(int r=r1-1;r<r2;r++)
        {
            sum+=sum_by_row[r][c2];
            sum-=sum_by_row[r][c1-1];
        }
        printf("%ld\n",sum);
    }

    return 0;
}
