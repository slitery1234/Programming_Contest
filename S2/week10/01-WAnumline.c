#include <stdio.h>
#include <stdlib.h>

long long int go_on(int move[],int dis,int n,long long int cyc_e)
{
    int cycle=0;
    int day=0;
    long long int k=0;

    if (dis == 0)
    {
        return 0;
    }
    else
    {
        if(cyc_e==0)    //can't reach
            return -1;

        if(dis > cyc_e)     //let dis smaller than one cycle
        {
            cycle = dis / cyc_e;
            dis = dis % cyc_e;
            if(dis == 0)
            {
                cycle --;
                dis += cyc_e;
            }
        }
        else
        {
            //do nothing
        }

        for(int i=0; i<n; i++)
        {
            if(move[i] == 1)
            {
                if(dis > 2)
                {
                    dis = dis -2;
                    day++;
                }
                else
                {
                    k = cycle * n + day + 1;
                    return k;
                }
            }
            else if(move[i] == 0)
            {
                if(dis > 1)
                {
                    dis = dis -1;
                    day++;
                }
                else
                {
                    k = cycle * n + day + 1;
                    return k;
                }
            }
            else
            {
                day++;
            }
        }
    }

}



int main()
{
    int N;
    scanf("%d",&N);
    char wind[N];
    scanf("%s",wind);
    int wind_move[N];
    long long int max_cycle_east_move=0;

    for(int i=0; i<N; i++)
    {
        if(wind[i] == 'W')
        {
            wind_move[i]=-1;
        }
        else if(wind[i] == 'E')
        {
            wind_move[i]=1;
            max_cycle_east_move+=2;
        }
        else
        {
            wind_move[i]=0;
            max_cycle_east_move+=1;
        }
    }

    int treasure_position=0;
    scanf("%d",&treasure_position);
    int dis = treasure_position - 0;

    long long int ans = go_on(wind_move,dis,N,max_cycle_east_move);
    printf("%lld",ans);

    return 0;
}
