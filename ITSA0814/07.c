#include <stdio.h>
#include <stdlib.h>

void can_walk(int x,int y,int map[x][y],int x1,int y1,int reachable[x][y])
{
    if(map[x1][y1]==1)  //position 1
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

    }
}


int main()
{
    int nc;
    scanf("%d",&nc);
    for(int nci=0; nci<nc; nci++)
    {
        int n;
        scanf("%d",&n);
        int map[n][n],reachable[n][n];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                map[i][j]=0;
            }
        }
        int barrs;
        scanf("%d",&barrs);
        for(int i=0;i<barrs;i++)
        {
            int barrx,barry;
            scanf("%d%d",&barrx,&barry);
            map[barrx-1][barry-1]=1;
        }
        int p_x,p_y;
        scanf("%d%d",&p_x,&p_y);
        can_walk(n,n,map,p_x-1,p_y-1,reachable);


        int reach = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(reachable[i][j] == 1)
                    reach++;
            }
        }

        printf("%d\n",reach);
    }
    return 0;
}
