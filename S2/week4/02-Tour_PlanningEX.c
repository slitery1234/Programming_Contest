#include <stdio.h>
#include <stdlib.h>

int can_walk(int x,int y,int map[x][y],int x1,int y1,int x2,int y2,int reachable[x][y])
{
    if(map[x1][y1]==1)  //position 1 is block
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

        if(reachable[x2][y2]==1)
        {
            return 1;
        }
        else
            return 0;



    }
}

/*

reachable
1 -> reachable
2 -> walked

road
1=x+1,2=y+1
-1=x-1,-2=y-1
*/


int route(int x,int y,int x1,int y1,int x2,int y2,int reach[x][y],int road[])
{
    int tried;
    int tried_times=0;
    reach[x1][y1]=2;
    road[tried_times]=0;

    while( !(tried == -1) )
    {
        tried = 0;
        if( (x1-1 >=0) || (x1+1 <x) || ( y1-1 >=0) || ( y1+1 <y) )
        {
            if((x1 == x2) && (y1 == y2))
                tried=-1;

            if(x1-1 >=0 && tried==0)
            {
                if( reach[x1-1][y1] == 1)
                {
                    reach[x1-1][y1]=2;
                    x1--;
                    tried=1;
                    tried_times++;
                    road[tried_times]=-1;
                }
            }
            if(x1+1 <x && tried==0)
            {
                if( reach[x1+1][y1] == 1)
                {
                    reach[x1+1][y1]=2;
                    x1++;
                    tried=1;
                    tried_times++;
                    road[tried_times]=1;
                }
            }
            if(y1-1 >=0 && tried==0)
            {
                if( reach[x1][y1-1] == 1)
                {
                    reach[x1][y1-1]=2;
                    y1--;
                    tried=1;
                    tried_times++;
                    road[tried_times]=-2;
                }
            }
            if(y1+1 <y && tried==0)
            {
                if( reach[x1][y1+1] == 1)
                {
                    reach[x1][y1+1]=2;
                    y1++;
                    tried=1;
                    tried_times++;
                    road[tried_times]=2;
                }
            }

            //------------------------------------------
            if(tried == 0 && tried_times >=1)
            {
                if(road[tried_times]==1)
                    x1--;
                else if(road[tried_times]==-1)
                    x1++;
                else if(road[tried_times]==2)
                    y1--;
                else if(road[tried_times]==-2)
                    y1++;
                road[tried_times]=0;
                tried_times--;
            }

        }
        //printf("%d\n",tried_times);

        //printf("%d : %d ,(x,y)=(%d,%d)\n",tried_times-1,road[tried_times-1],x1,y1);
    }

    return tried_times;
}


int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int map[n][m];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            scanf("%d",&map[i][j]);
    }

    int p1_x,p1_y,p2_x,p2_y;
    scanf("%d %d",&p1_x,&p1_y);
    scanf("%d %d",&p2_x,&p2_y);

    int reachable[n][m];

    int a=n*m;
    int road[a];
    for(int i=0; i<a; i++)
        road[i]=0;



    int reach = can_walk(n,m,map,p1_x-1,p1_y-1,p2_x-1,p2_y-1,reachable);

    /*for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            printf("%d ",reachable[i][j]);
        printf("\n");
    }*/

    if(reach == 1)
    {
        int t=route(n,m,p1_x-1,p1_y-1,p2_x-1,p2_y-1,reachable,road);
        printf("%d %d\n",p1_x,p1_y);
        for(int i=0; i<t; i++)
        {
            if(road[i] == 1)
            {
                p1_x++;
                printf("%d %d\n",p1_x,p1_y);
            }
            else if(road[i] == -1)
            {
                p1_x--;
                printf("%d %d\n",p1_x,p1_y);
            }
            else if(road[i] == 2)
            {
                p1_y++;
                printf("%d %d\n",p1_x,p1_y);
            }
            else if(road[i] == -2)
            {
                p1_y--;
                printf("%d %d\n",p1_x,p1_y);
            }
        }
        printf("%d %d\n",p2_x,p2_y);
    }
    else if (reach == 0)
        printf("-1");

    return 0;
}
