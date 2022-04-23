#include <stdio.h>
int n,m;
int k;
char ip[52][52];
int test[52][52];
int dfs(int x,int y)
{
    test[x][y] = 1;
    int ans = (ip[x][y] == '*');
    if(ip[x-1][y] != 'X' && test[x-1][y] == 0)
        ans += dfs(x-1,y);
    if(ip[x+1][y] != 'X' && test[x+1][y] == 0)
        ans += dfs(x+1,y);
    if(ip[x][y-1] != 'X' && test[x][y-1] == 0)
        ans += dfs(x,y-1);
    if(ip[x][y+1] != 'X' && test[x][y+1] == 0)
        ans += dfs(x,y+1);
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<52;i++)
    {
        for(int j=0;j<52;j++)
            ip[i][j] = 'X';
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%c",&ip[i][j]);
            test[i][j] = 0;
            if(ip[i][j]!='.' && ip[i][j]!='*' && ip[i][j]!='X')
                j--;
        }
    }
    int x0,y0;
    scanf("%d%d",&x0,&y0);
    printf("%d\n",dfs(x0,y0));
    return 0;
}

