#include <stdio.h>
int n,m;
int k;
char ip[105][105];
int kill(int x,int y)
{
    int ans=0;
    for(int i=x;x-i<=k;i--)
    {
        if(ip[i][y] == '@')
        {
            ans ++;
            ip[i][y] = '.';
        }
        if(ip[i][y] == '#')
            break;
    }
    for(int i=x;i-x<=k;i++)
    {
        if(ip[i][y] == '@')
        {
            ans ++;
            ip[i][y] = '.';
        }
        if(ip[i][y] == '#')
            break;
    }
    for(int i=y;y-i<=k;i--)
    {
        if(ip[x][i] == '@')
        {
            ans ++;
            ip[x][i] = '.';
        }
        if(ip[x][i] == '#')
            break;
    }
    for(int i=y;i-y<=k;i++)
    {
        if(ip[x][i] == '@')
        {
            ans ++;
            ip[x][i] = '.';
        }
        if(ip[x][i] == '#')
            break;
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    int boom[n*m][2],bcnt=0;
    for(int i=0;i<105;i++)
    {
        for(int j=0;j<105;j++)
            ip[i][j] = '#';
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%c",&ip[i][j]);
            if(ip[i][j]!='.' && ip[i][j]!='#' && ip[i][j]!='+' && ip[i][j]!='@')
                j--;
            if(ip[i][j] == '+')
            {
                boom[bcnt][0] = i;
                boom[bcnt][1] = j;
                bcnt++;
            }
        }
    }
    scanf("%d",&k);
    int ans = 0;
    for(int i=0;i<bcnt;i++)
        ans += kill(boom[i][0],boom[i][1]);
    printf("%d\n",ans);
    return 0;
}

