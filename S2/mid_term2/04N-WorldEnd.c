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
//^INPUT
//-------------------------------------------
    if( xn + yn + n < 0)    //forever can't reach
    {
        printf("-1\n");
    }
    else
    {
        long long int dis_x=0,dis_y=0;
        long long int d=0;
        long long int minday = 1000000000000;
        long long int d_left=0 , d_right=minday;
        long long int dk , di;
        long long int dx , dy;
        int answered=0;

//--------------------------------------
//Binary search
        while( d_left <= d_right )
        {
            d = (d_left + d_right)/2 ;
            dk = (d-1) /n;
            di = (d-1) %n;
            dis_x = treas[0] - (dk*xn + day_posi[di][0]) ;
            dis_y = treas[1] - (dk*yn + day_posi[di][1]) ;

            if(dis_x < 0)
                dis_x *= -1;
            if(dis_y < 0)
                dis_y *= -1;

            if(dis_x + dis_y > d)
            {
                d_left = d+1;
            }
            else if (dis_x + dis_y <= d) //maybe can reach
            {
                dx = dis_x;
                dy = d-dx;

                if(dis_y <= dy)         //it can reach
                {
                    answered = 1;
                    if(minday > d)
                        minday = d;
                }
                else                    //can't reach
                {
                    //do nothing
                }

                d_right = d-1;
            }
        }
        if(answered == 1)
            printf("%lld\n",minday);
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
can reach (kxn + xi + Dx , kyn + yi + Dy)
=> can reach any point - ( kxn + xi , kyn + yi ) < D
xn,yn: x,y of a cycle can reach
xi,yi: x,y at i day can reach
*/
