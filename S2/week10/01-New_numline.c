#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d",&N);
    char wind[N];
    scanf("%s",wind);
    long long int wind_move[N];
    long long int max_cycle_move=0;

    for(int i=0; i<N; i++)
    {
        if(wind[i] == 'W')
        {
            wind_move[i]=-1;
        }
        else if(wind[i] == 'E')
        {
            wind_move[i]=1;
            max_cycle_move+=2;
        }
        else
            wind_move[i]=0;
    }

    long long int treasure_position=0;
    scanf("%lld",&treasure_position);

    if (max_cycle_move == 0)
    {
        printf("-1");
    }
    else
    {
        long long int cycle = treasure_position / max_cycle_move;
        long long int dis = treasure_position % max_cycle_move;
        long long int day = 0;

        if(dis == 0)
        {
            cycle--;
            dis = max_cycle_move;
        }
        for(int i=0; i<N; i++)
        {
            if(dis > 0)
            {
                if(wind_move[i] == -1)
                {
                    day ++;
                }
                else if(wind_move[i] == 1)
                {
                    dis = dis -2;
                    day ++;
                }
            }
        }
        //printf("%lld,%lld,%lld",cycle,dis,day);
        printf("%lld",cycle * N + day);

    }
    return 0;
}
