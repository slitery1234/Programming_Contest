#include <stdio.h>
#include <stdlib.h>


/*
int explore_map ( const int n, const int m,
                  const int grid_map[n][m], int reachable[n][m],
                  const int k, const int directions[k][2],
                  const int current_position[2] );


int main()
{
    int x;
    const int n=3;
    const int m=4;
    const int k=4;

    const int grid_map[n][m];//={{0,0,0,0},{1,0,1,0},{1,1,0,1}};
    int reachable[n][m];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&grid_map[i][j]);
            reachable[i][j]=0;
        }
    }
    const int directions[4][2]; //={{ -1, 0 },{ 0, -1 },{ 1, 0 },{ 0, 1 }}
    for(int i=0; i<k; i++)
    {
        scanf("%d%d",&directions[i][0],&directions[i][1]);
    }
    const int current_position[2]={0,0};



    x=explore_map(n,m,grid_map,reachable,k,directions,current_position);
    int is_test[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            is_test[i][j]=0;
    }

    int new_position[2];
    new_position[0]=current_position[0];
    new_position[1]=current_position[1];
    reachable[ new_position[0] ][ new_position[1] ]=1;

    int tried=0;
    while(1)
    {
        tried=0;

        for(int i=0; i<k; i++)
        {

            if( (new_position[0] + directions[i][0]>-1) && (new_position[0] + directions[i][0]<n) && (new_position[1] + directions[i][1]>-1) && (new_position[1] + directions[i][1]<m))
            {
                if( grid_map[ new_position[0] + directions[i][0] ][ new_position[1] + directions[i][1] ] == 0)
                reachable[ new_position[0] + directions[i][0] ][ new_position[1] + directions[i][1] ] = 1;
            }

        }
        is_test[ new_position[0] ][ new_position[1] ]=1;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(reachable[i][j]==1 && is_test[i][j]==0)
                {
                    new_position[0]=i;
                    new_position[1]=j;
                    tried++;
                }
            }
        }

        if(tried==0)
            break;
    }
    return 0;
}*/

int explore_map ( const int n, const int m,
                  const int grid_map[n][m], int reachable[n][m],
                  const int k, const int directions[k][2],
                  const int current_position[2] )
{
    int is_test[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            is_test[i][j]=0;
    }

    int new_position[2];
    new_position[0]=current_position[0];
    new_position[1]=current_position[1];
    reachable[ new_position[0] ][ new_position[1] ]=1;

    int tried;
    while(1)
    {
        tried=0;

        for(int i=0; i<k; i++)
        {
            if( (new_position[0] + directions[i][0]>-1) && (new_position[0] + directions[i][0]<n) && (new_position[1] + directions[i][1]>-1) && (new_position[1] + directions[i][1]<m))
            {
                if( grid_map[ new_position[0] + directions[i][0] ][ new_position[1] + directions[i][1] ] == 0)
                reachable[ new_position[0] + directions[i][0] ][ new_position[1] + directions[i][1] ] = 1;
            }

        }
        is_test[ new_position[0] ][ new_position[1] ]=1;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(reachable[i][j]==1 && is_test[i][j]==0)
                {
                    new_position[0]=i;
                    new_position[1]=j;
                    tried++;
                }
            }
        }

        if(tried==0)
            break;
    }
    return 0;
}
/*0 1 0 0 0
0 0 - 0 1
0 - * - 0 1
0 1 1 1 1
0 0 0 0 0
0 1 1 0 1*/
