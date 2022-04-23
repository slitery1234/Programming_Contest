//https://vjudge.net/problem/10046/origin

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

pair<int,int> input[2000000];
pair<int,int> sortedinput[2000000];

int n,t;

bool sort_func(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.first!=p2.first)
        return p1.first<p2.first;
    else
        return p1.second>p2.second;
}


int main()
{

    scanf("%d%d",&n,&t);
    for(int i=0; i<n; i++)
        scanf("%d%d",&input[i].first,&input[i].second);
    sort(input,input+n,sort_func);
    int temp = 0;
    int xx = 0;
    for(int i=0; i<n; i++)
    {
        if(temp != input[i].first)
        {
            temp = input[i].first;
            sortedinput[xx].first = input[i].first;
            sortedinput[xx].second = input[i].second;
            xx++;
        }
        // else skip
    }

    temp = 0;
/*
    for(int i=0;i<xx;i++)
        printf("%d %d\n",sortedinput[i].first,sortedinput[i].second);
    printf("\n");
*/


    if(sortedinput[0].first != 1)
    {
        printf("-1\n");
    }
    else
    {
        int lend = sortedinput[0].second;
        temp = lend;
        int ans = 1;
        int found = 0;

        for(int prog=1; prog<xx; prog++)
        {
            if(sortedinput[prog].first <= lend+1)
            {
                if(sortedinput[prog].second > temp)
                {
                    found = 1;
                    temp = sortedinput[prog].second;
                }
            }
            else
            {
                if(found == 0)
                {
                    //printf("nf");
                    ans = -1;
                    break;
                }
                else
                {
                    found = 0;
                    lend = temp;
                    ans++;
                    prog--;
                }
            }

            if((temp == t) && (lend!=temp))
            {
                ans++;
                break;
            }
        }

        if(temp == t)
            printf("%d\n",ans);
        else
            printf("-1\n");
    }

    return 0;
}
