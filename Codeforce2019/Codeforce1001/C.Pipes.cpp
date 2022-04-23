#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nc;
    scanf("%d",&nc);
    for(int ni=0; ni<nc; ni++)
    {
        int n;
        scanf("%d",&n);
        char u[n+4],d[n+4];
        int up[n],down[n];

        scanf("%s",u);
        scanf("%s",d);

        int waterud=0;
        int ans = 1;
        for(int i=0; i<n; i++)
        {
            if(u[i] == '1' || u[i] == '2')
                up[i] = 0;
            else if(u[i] == '3' || u[i] == '4' || u[i] == '5' || u[i] == '6')
                up[i] = 1;
        }
        for(int i=0; i<n; i++)
        {
            if(d[i] == '1' || d[i] == '2')
                down[i] = 0;
            else if(d[i] == '3' || d[i] == '4' || d[i] == '5' || d[i] == '6')
                down[i] = 1;
        }
        for(int i=0; i<n; i++)
        {
            if(waterud == 0)
            {
                if(up[i] == 0)
                {
                    //do nothing
                }
                else
                {
                    if(down[i] == 0)
                    {
                        ans = 0;
                        break;
                    }
                    else
                    {
                        waterud = 1;
                    }
                }
            }
            else
            {
                if(down[i] == 0)
                {
                    //do nothing
                }
                else
                {
                    if(up[i] == 0)
                    {
                        ans = 0;
                        break;
                    }
                    else
                    {
                        waterud = 0;
                    }
                }
            }
        }

        if(waterud == 1 && ans == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
