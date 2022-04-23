#include <stdio.h>
#include <stdlib.h>

int can_walk(int x,int y,int map[x][y],int x1,int y1,int x2,int y2)
{
    if(map[x1][y1]==1)  //position 1 «DªÅ
        return 0;
    else
    {
        int new_x,new_y;
        int is_test[x][y];
        int reachable[x][y];
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

        if(reachable[x2][y2]==1)
            return 1;
        else
            return 0;



    }
}


int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int map[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            scanf("%d",&map[i][j]);
    }

    int p1_x,p1_y,p2_x,p2_y;
    scanf("%d %d",&p1_x,&p1_y);
    scanf("%d %d",&p2_x,&p2_y);


    int reach = can_walk(n,m,map,p1_x-1,p1_y-1,p2_x-1,p2_y-1);

    if(reach == 1)
        printf("Yes");
    else if (reach == 0)
        printf("No");

    return 0;
}
