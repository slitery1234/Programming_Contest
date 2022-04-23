#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    int length[n];
    int subsequence[n][n];
    int max_len=0,max_i=0;

    for(int i=0;i<n;i++)
        length[i]=1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==0)
                subsequence[i][j]=i;
            else
                subsequence[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",subsequence[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
