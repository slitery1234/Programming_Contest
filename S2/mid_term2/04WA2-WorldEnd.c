#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    char wind[n];
    scanf("%s",wind);
    int wind_move[n][2];

    long long int posi[2];
    long long int treas[2];
    long long int day_posi[n][2];
    posi[0]=0;
    posi[1]=0;
    scanf("%lld%lld",&treas[0],&treas[1]);

    for(int i=0; i<n; i++)
    {
        if(wind[i] == 'W')
        {
            wind_move[i][0]=-1;
            wind_move[i][1]=0;
        }
        else if(wind[i] == 'E')
        {
            wind_move[i][0]=1;
            wind_move[i][1]=0;
        }
        else if(wind[i] == 'S')
        {
            wind_move[i][0]=0;
            wind_move[i][1]=-1;
        }
        else if(wind[i] == 'N')
        {
            wind_move[i][0]=0;
            wind_move[i][1]=1;
        }
    }

    for(int i=0; i<n; i++)
    {
        posi[0]= posi[0] + wind_move[i][0];
        posi[1]= posi[1] + wind_move[i][1];

        day_posi[i][0]=posi[0];
        day_posi[i][1]=posi[1];
    }
    long long int xn = day_posi[n-1][0];
    long long int yn = day_posi[n-1][1];

    if( xn + yn + n < 0)
    {
        printf("-1\n");
    }
    else
    {
        long long int dis_x=0,dis_y=0;
        long long int k=0;
        long long int minday = 10000000000;
        long long int k_left , k_right;

        for(int i=0; i<n; i++)
        {
            k_left = 0;
            k_right = 100000000;

            while( (dis_x + dis_y != k*n + (i+1)) && k_left <= k_right )
            {
                k = (k_left + k_right)/2;

                dis_x = treas[0] - day_posi[i][0]- k*xn;
                dis_y = treas[1] - day_posi[i][1]- k*yn;

                if(dis_x + dis_y < k*n+ (i+1) || dis_x + dis_y == k*n + (i+1))
                {
                    k_right = k-1;
                }
                else if(dis_x + dis_y > k*n + (i+1) )
                {
                    k_left = k+1;
                }
            }
            if(dis_x + dis_y > k*n+ (i+1) )
            {
                k++;
            }
            if( k*n + (i+1) < minday)
                minday = k*n + (i+1);
        }

        long long int m = minday;
        long long int error=-1;

        for(int i=0;i<n;i++)
        {
            m = minday - i;
            k = (minday - (i+1)) / n ;
            long long int r = (minday - (i+1)) % n;

            if((treas[0]-k*xn-day_posi[r][0]) +(treas[1]-k*yn-day_posi[r][1]) <= m)
            {
                for(long long int j=0;j<=m;j++)
                {
                    if( (treas[0]-k*xn-day_posi[r][0] <= j) && (treas[1]-k*yn-day_posi[r][1] <= m-j ) )
                    {
                        error = i;
                        break;
                    }
                }
            }
        }
        if(error != -1)
            printf("%lld\n",minday - error);
        else
            printf("-1\n");
        return 0;



    }

}

/*
D DAYS
a cycle has n days
=> D = k*n+i
k: k cycles
i: i days

from (0,0) go D days
can reach (kxn + xi + Da , kyn + yi + Db)
=> can reach any point - ( kxn + xi , kyn + yi ) < D
xn,yn: x,y of a cycle can reach
xi,yi: x,y at i day can reach
*/
