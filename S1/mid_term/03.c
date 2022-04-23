#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m=0,n=0;
    scanf("%d%d",&m,&n);
    int i=0,j=0,a[m][n];
    int x4=0,x3=0,x1=0,x0=0;
    int count=0;

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            count=0;
            if(a[i][j]==0)
            {
                if(i!=0)
                {
                    if(a[i-1][j]==0)
                        count+=1;
                }
                if(j!=0)
                {
                    if(a[i][j-1]==0)
                        count+=1;
                }
                if(i!=(m-1))
                {
                    if(a[i+1][j]==0)
                        count+=1;
                }
                if(j!=(n-1))
                {
                    if(a[i][j+1]==0)
                        count+=1;
                }
                switch(count)
                {
                case 4:
                    x4+=1;
                    break;
                case 3:
                    x3+=1;
                    break;
                case 1:
                    x1+=1;
                    break;
                case 0:
                    x0+=1;
                    break;
                default:
                    break;
            }
            }


        }
    }

    printf("%d %d %d %d",x4,x3,x1,x0);

    return 0;
}
