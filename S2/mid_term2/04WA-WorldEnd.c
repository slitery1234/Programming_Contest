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

    long long int dis_x=0,dis_y=0;
    long long int k=0;
    long long int minday = 10000000000;
    long long int k_left , k_right;
    long long int xn = day_posi[n-1][0];
    long long int yn = day_posi[n-1][1];
    int already_answer=0;

    if (xn + yn < 0)
    {
        printf("-1");
        already_answer=1;
    }
    else
    {
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

            if(dis_x <0 || dis_y <0)
            {
                //do nothing
            }
            else if( k*n + (i+1) < minday)
                minday = k*n + (i+1);

            printf("%lld %lld \n",dis_x,dis_y);
            printf("%lld %d %d \n\n",k,n,i+1);
        }

    }

    if(already_answer == 0)
    {
        long long int m;
        int  i;
        for(i=0;i<n;i++)
        {
            m = minday - (i+1);
            k = m / n;

            dis_x = treas[0] - day_posi[i][0] - k*xn;
            dis_y = treas[1] - day_posi[i][1] - k*yn;

            if(dis_x < 0)
                dis_x *=-1;
            if(dis_y <0)
                dis_y *=-1;

            if(dis_x + dis_y > m)
                break;
        }
        if(i != n)
            printf("%lld",m+1);
        else
            printf("-1");
    }
    else
    {
        //do nothing
    }

    return 0;
}
/*
k cycle + i day
xi + dis_x  = trea_x
dis_x = trea_x - xi
if at k cycle
dis_x = |trea x - (xi+kxn)|

dis_x < k * na + ia

yi + dis_y  = trea_y
dis_y = |trea y - (yi+kyn)|

dis_y < k * nb + ib

na+nb = n
ia+ib = i

dis_x + dis_y < k(n+xn+yn) + i
*/

/*
3
NWN
4 2
*/
