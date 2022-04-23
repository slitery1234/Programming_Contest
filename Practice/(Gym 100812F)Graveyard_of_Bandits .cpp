#include <iostream>
using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int ip[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char c;
            scanf("%c",&c);
            if(c == '.')
                ip[i][j] = 0;
            else if(c == '+')
                ip[i][j] = 1;
            else
                j--;
        }
    }
    int testcase = max(n,m);
    int ans[testcase];
    int ct = 0;
    for(int i=0;i<=testcase;i++)
        ans[i]=0;

    for(int i=0;i<n;i++)
    {
        ct = 0;
        for(int j=0;j<m;j++)
        {
            if(ip[i][j] == 0)
            {
                ans[ct]++;
                ct++;
            }
            else
                ct = 0;
        }
    }

    ct = 0;
    for(int j=0;j<m;j++)
    {
        ct = 0;
        for(int i=0;i<n;i++)
        {
            if(ip[i][j] == 0)
            {
                ans[ct]++;
                ct++;
            }
            else
                ct = 0;
        }
    }

    for(int i=testcase-1;i>=0;i--)
        ans[i]+=ans[i+1];

    printf("%d ",ans[0]/2);
    for(int i=1;i<testcase;i++)
        printf("%d ",ans[i]);
    return 0;
}
