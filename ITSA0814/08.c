#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b)
{
    int c = *(int *)a;
    int d = *(int *)b;
    if(c < d)
        return -1;
    else if(c == d)
        return 0;
    else
        return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];
    int b_found[n];
    int g_found[n];


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
        }
        b_found[i]=0;
        g_found[i]=0;
    }

    for(int x=0; x<n; x++)
    {
        int max=0;
        int temp_b,temp_g;
        for(int i=0; i<n; i++)
        {
            if(b_found[i] == 1)
                continue;
            for(int j=0; j<n; j++)
            {
                if(g_found[j] == 1)
                    continue;

                if(a[i][j] > max)
                {
                    temp_b=i;
                    temp_g=j;
                    max = a[i][j];
                }
            }
        }
        b_found[temp_b]=1;
        g_found[temp_g]=1;

        printf("boy %d pair with girl %d\n",temp_b+1,temp_g+1);
    }

    return 0;
}
