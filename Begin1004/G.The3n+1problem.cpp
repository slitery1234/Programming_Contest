#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int,int> leng;
    int l,r;
    while(scanf("%d %d",&l,&r) != EOF)
    {
        int oril=l;
        int orir=r;
        if(l > r)
            swap(l,r);
        int maxx = 0;
        for(int i=l;i<=r;i++)
        {
            if(leng.count(i) == 0)
            {
                int ti = i;
                int x = 1;
                while(ti != 1)
                {
                    if(ti % 2 == 1)
                        ti = 3*ti+1;
                    else
                        ti = ti/2;
                    x++;
                }
                leng.insert(make_pair(i,x));
            }

            if(leng[i] > maxx)
                maxx = leng[i];
        }
        printf("%d %d %d\n",oril,orir,maxx);
    }
    return 0;
}
