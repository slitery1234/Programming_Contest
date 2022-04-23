#include <bits/stdc++.h>
using namespace std;

int s[100];
int n,l,cnt;

int check(int leng)
{
    int checked = 0;

    for(int i=leng-1; i>=(leng/2+(leng%2)) ;i--)
    {
        checked = 0;
        int len = leng - i;
        int Ls[len],Rs[len];

        for(int j=0;j<len;j++)
        {
            if(i-len+j < 0)
                continue;
            if(i+j >= leng)
                continue;
            Rs[j] = s[i+j];
            Ls[j] = s[i-len+j];
        }

        for(int j=0;j<len;j++)
        {
            if(Ls[j] != Rs[j])
                checked = 1;
        }
        if(checked == 0)
            return 0;
    }

    return 1;
}

int dfs(int siz)
{
    int t=1;
    for(int i=0;i<l;i++)
    {
        s[siz] = i;
        if(check(siz+1))
        {
            cnt ++;
            if(cnt == n)
            {
                for(int j=0;j<=siz;j++)
                {
                    if(j == 64)
                        printf("\n");
                    else if(j%4 == 0 && j!=0)
                        printf(" ");
                    printf("%c",s[j]+'A');
                }
                printf("\n%d\n",siz+1);
                return 0;
            }
            t = dfs(siz+1);
            if(t == 0)
                return 0;
        }
    }
    return 1;
}

int main()
{
    scanf("%d %d",&n,&l);
    while(n!=0 || l!=0)
    {
        cnt = 0;
        dfs(0);
        scanf("%d %d",&n,&l);
    }
}
