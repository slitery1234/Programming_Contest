#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q,n;
    scanf("%d",&q);
    for(int ni=0;ni<q;ni++)
    {
        scanf("%d",&n);
        int rul[n+4],ans[n+4],t[n+4];
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&rul[i]);
            ans[i] = 0;
            t[i] = 0;
        }
        int temp,book,ori;
        for(int i=1;i<=n;i++)
        {
            temp = 1;
            if(ans[i] == 0)
            {
                t[0] = i;
                ori = i;
                book = i;

                while(rul[book] != ori)
                {
                    t[temp] = book;
                    temp ++;
                    book = rul[book];
                }

                for(int j=0;j<temp;j++)
                {
                    ans[t[j]] = temp;
                }
            }
        }
        for(int i=1;i<=n;i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
