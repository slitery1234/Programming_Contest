#include <bits/stdc++.h>
using namespace std;

int team_up(int i,int team_num,vector <int> team[],vector <int> v[],int is_test[])
{
    if(!is_test[i])
    {
        is_test[i]=1;
        team[team_num].push_back(i);
        for(int j=0;j<v[i].size();j++)
        {
            if(!is_test[v[i][j]])
            {
                int t = team_up(v[i][j],team_num,team,v,is_test);
            }
        }
        return team_num+1;
    }
    return team_num;
}


int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    int score[n];
    int is_test[n];
    vector <int> v[n];
    vector <int> team[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&score[i]);
        is_test[i]=0;
    }
    int x,y;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        if(x!=y)
        {
            v[x-1].push_back(y-1);
            v[y-1].push_back(x-1);
        }
    }

    int t=0;
    for(int i=0;i<n;i++)
    {
        t = team_up(i,t,team,v,is_test);
    }

    float max_avarage_score=0,i_score=0;
    int max_team=0;
    int team_score[t];

    for(int i=0;i<t;i++)
    {
        team_score[i]=0;
        for(int j=0;j<team[i].size();j++)
        {
            team_score[i]+=score[team[i][j]];
        }
        i_score = team_score[i] / team[i].size();
        if( i_score > max_avarage_score)
        {
            max_avarage_score = i_score;
            max_team = i;
        }
        else if( i_score == max_avarage_score)
        {
            if(team[i][0] < team[max_team][0])
            {
                max_avarage_score = i_score;
                max_team = i;
            }
        }
    }

    for(int i=0;i<team[max_team].size();i++)
    {
        printf("%d ",team[max_team][i]+1);
    }



/*
    printf("\n");
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<team[i].size();j++)
        {
            printf("%d ",team[i][j]);
        }
        printf("\n");
    }
*/
    return 0;
}
