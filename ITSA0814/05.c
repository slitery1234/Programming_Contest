#include <stdio.h>
#include <stdlib.h>

void can_walk(int x,int y,int map[x][y],int x1,int y1,int reachable[x][y])
{
    if(map[x1][y1]==1)
        return;
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

    }
}


int main()
{
    int n,m;
    scanf("%d%d",&m,&n);
    int map[n][m],reachable[n][m];
    int farm[n][m];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&farm[i][j]);
            reachable[i][j]=0;
            if(farm[i][j]!=0)
                map[i][j]=0;
            else
                map[i][j]=1;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            can_walk(n,m,map,i,j,reachable);
        }
    }






    return 0;
}

