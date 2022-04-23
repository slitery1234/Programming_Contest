#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    int a[n1][n2];
    int x4=0,x3=0,x1=0,x0=0;
    int t=0;

    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
            scanf("%d",&a[i][j]);
    }
     for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            if(a[i][j]==0)
            {
                if( i != 0 )
                {
                    if(a[i-1][j]==0)
                        t++;
                }
                if( (i+1)!= n1 )
                {
                    if(a[i+1][j]==0)
                        t++;
                }
                if( j != 0 )
                {
                    if(a[i][j-1]==0)
                        t++;
                }
                if( (j+1) != n2 )
                {
                    if(a[i][j+1]==0)
                        t++;
                }

                switch(t)
                {
                    case 0:
                        x0+=1;
                        break;
                    case 1:
                        x1+=1;
                        break;
                    case 3:
                        x3+=1;
                        break;
                    case 4:
                        x4+=1;
                        break;
                    default:
                        break;
                }

                t=0;
            }
        }
    }
    printf("%d %d %d %d",x4,x3,x1,x0);

    return 0;
}
