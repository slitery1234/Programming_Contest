#include <stdio.h>
#include <stdlib.h>

void can_walk(int x,int y,int map[x][y],int x1,int y1,int reachable[x][y])
{
    if(map[x1][y1]==1)  //position 1 «DªÅ
        return 0;
    else
    {
        int new_x,new_y;
        int is_test[x][y];
        int tried;

        for(int i=0; i<x; i++)
        {
            for(int j=0; j<y; j++)
            {
                is_test[i][j]=0;
                reachable[i][j]=0;
            }
        }
        reachable[x1][y1]=1;
        while(1)
        {
            tried=0;
            if( x1-1 >=0)
            {
                if( map[x1-1][y1] == 0)
                    reachable[x1-1][y1]=1;
            }
            if( x1+1 <x)
            {
                if( map[x1+1][y1] == 0)
                    reachable[x1+1][y1]=1;
            }
            if( y1-1 >=0)
            {
                if( map[x1][y1-1] == 0)
                    reachable[x1][y1-1]=1;
            }
            if( y1+1 <y)
            {
                if( map[x1][y1+1] == 0)
                    reachable[x1][y1+1]=1;
            }
            is_test[x1][y1]=1;

            for(int i=0; i<x; i++)
            {
                for(int j=0; j<y; j++)
                {
                    if(reachable[i][j]==1 && is_test[i][j]==0)
                    {
                        x1=i;
                        y1=j;
                        tried++;
                    }
                }
            }

            if(tried==0)
                break;
        }

        /*for(int i=0; i<x; i++)
        {
            for(int j=0; j<y; j++)
            {
                printf("%d ",reachable[i][j]);
            }
            printf("\n");
        }*/

/*        if(reachable[x2][y2]==1)
            return 1;
        else
            return 0;
*/


    }
}


int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int map[n][m],reachable[n][m];
    int treasure_x[5000],treasure_y[5000];
    int treasure_n=0;
    char c;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            reachable[i][j]=0;

            scanf("%c",&c);
            if(c=='X')
                map[i][j]=1;
            else if(c=='.')
                map[i][j]=0;
            else if(c=='\n'||c=='\r')
            {
                j--;
            }
            else
            {
                map[i][j]=0;
                treasure_x[treasure_n]=i;
                treasure_y[treasure_n]=j;
                treasure_n++;
            }
        }
    }
    int p_x,p_y;
    scanf("%d %d",&p_x,&p_y);
    can_walk(n,m,map,p_x-1,p_y-1,reachable);


  /*  for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }

*/
    int reach = 0;

    for(int i=0;i<treasure_n;i++)
    {
        if(reachable[ treasure_x[i] ][ treasure_y[i] ] == 1)
            reach++;
    }

    printf("%d",reach);

    return 0;
}
