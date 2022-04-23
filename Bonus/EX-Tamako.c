#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int score[n];
    int team[n][n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&score[i]);
        for(int j=0;j<n;j++)
            team[i][j]=0;
        team[i][i]=1;
    }

    int x,y;

    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        team[x-1][y-1]=1;
        team[y-1][x-1]=1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(team[i][j] == 1 && (i!=j))
            {
                for(int k=i;k<n;k++)
                {
                    if(team[j][k] == 1)
                    {
                        team[i][k] = 1;
                        team[j][k] = 0;
                    }
                }
            }
        }
    }

    float avarage_score[n];
    int person[n];

    for(int i=0;i<n;i++)
    {
        person[i] = 0;
        avarage_score[i] = 0;
        for(int j=0;j<n;j++)
        {
            if(team[i][j] == 1)
            {
                person[i]++;
                avarage_score[i]+=score[j];
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(person[i] != 0)
            avarage_score[i]/=person[i];
    }

    int max_score=0;
    int max_i=0;
    int min_ia,min_ib;
    for(int i=0;i<n;i++)
    {
        if(avarage_score[i] > max_score)
        {
            max_score=avarage_score[i];
            max_i=i;
        }
        if(avarage_score[i] == max_score)
        {
            min_ia = n;
            min_ib = n;
            for(int j=0;j<n;j++)
            {
                if(team[i][j] == 1)
                {
                    if(j < min_ia)
                        min_ia = j;
                }
                if(team[max_i][j] == 1)
                {
                    if(j < min_ib)
                        min_ib = j;
                }
            }
            if(min_ia < min_ib)
            {
                max_score=avarage_score[i];
                max_i=i;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(team[max_i][i]==1)
            printf("%d ",i+1);
    }
    return 0;
}
