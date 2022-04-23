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
        int r,p,s;
        scanf("%d%d%d",&r,&p,&s);
        int tr = r;
        int tp = p;
        int ts = s;
        char st[n];
        for(int i=0; i<n; i++)
        {
            scanf("%c",&st[i]);
            if(st[i] == 'P')
            {
                if(s > 0)
                    s--;
            }
            else if(st[i] == 'S')
            {
                if(r > 0)
                    r--;
            }
            else if(st[i] == 'R')
            {
                if(p > 0)
                    p--;
            }
            else
                i--;
        }

        if( (s+r+p) <= n/2  )
        {
            printf("YES\n");
            for(int i=0; i<n; i++)
            {
                if(st[i] == 'P')
                {
                    if(ts > s)
                    {
                        ts--;
                        printf("S");
                    }
                    else if(r > 0)
                    {
                        tr--;
                        r--;
                        printf("R");
                    }
                    else
                    {
                        tp--;
                        p--;
                        printf("P");
                    }
                }
                else if(st[i] == 'S')
                {
                    if(tr > r)
                    {
                        tr--;
                        printf("R");
                    }
                    else if(s > 0)
                    {
                        ts--;
                        s--;
                        printf("S");
                    }
                    else
                    {
                        tp--;
                        p--;
                        printf("P");
                    }
                }
                else if(st[i] == 'R')
                {
                    if(tp > p)
                    {
                        tp--;
                        printf("P");
                    }
                    else if(s > 0)
                    {
                        ts--;
                        s--;
                        printf("S");
                    }
                    else
                    {
                        tr--;
                        r--;
                        printf("R");
                    }
                }
            }
            printf("\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
