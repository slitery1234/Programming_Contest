#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    int bigger_num[n][n];
    int route=0;
    int t;
    int pre_t=0;
    int max_a_i=0;

    for(int i=0; i<n; i++)
    {
        pre_t=t;
        t=0;
        for(int j=i; j<n; j++)
        {
            if(a[i]<a[j])
                t++;
        }

        if(t>pre_t)
        {
            route++;
            for(int j=0; j<i; j++)
                bigger_num[route][j]=bigger_num[0][j];
            for(int j=i;j<n;j++)
            {
                if(a[j]>a[i])
                    bigger_num[route][j]=bigger_num[route][i];
                else
                bigger_num[route][j]=0;

            }
        }

        bigger_num[0][i]=t;
    }

    for(int r=0; r<=route; r++)
    {
    for(int i=0;i<n;i++)
    {
        printf("%d ",bigger_num[r][i]);
    }
    printf("\n");
    }
    printf("\n");
    int max_length=0;

    for(int r=0; r<=route; r++)
    {
        max_length=0;
        for(int i=n-1; i>=0; i--)
        {
            if(bigger_num[r][i]>=max_length)
            {
                if( a[i] < max_a_i)
                {
                    max_length++;
                    max_a_i=a[i];
                    bigger_num[r][i]=max_length;
                }
                else
                {
                    bigger_num[r][i]=max_length;
                    max_a_i=a[i];
                }
            }
            else if(bigger_num[r][i]==-1)
            {
                bigger_num[r][i]=0;
            }
            else
            {
                for(int j=0; j<i; j++)
                    bigger_num[r][j]--;
            }
        }

    }

    int max_route=0;
    max_length=0;
    for(int r=0; r<=route; r++)
    {
        for(int i=0; i<n; i++)
        {
            if(bigger_num[r][i]>max_length)
            {
                max_length=bigger_num[r][i];
                max_route=r;
            }
            printf("%d ",bigger_num[r][i]);
        }
        printf("\n");
    }

    printf("%d",max_route);
    for(int i=0; i<n; i++)
    {
        if(bigger_num[max_route][i] == max_length)
        {
            printf("%d ",a[i]);
            max_length--;
        }
    }

}
