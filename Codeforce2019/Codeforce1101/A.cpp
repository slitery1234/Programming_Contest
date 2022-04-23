#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nc;
    scanf("%d",&nc);
    for(int ni=0;ni<nc;ni++)
    {
        int a,b,tmp;
        scanf("%d%d",&a,&b);
        while(b != 0)
        {
            if(a < b)
            {
                tmp = a;
                a = b;
                b = tmp;
            }
            else
            {
                tmp = b;
                b = a%b;
                a = tmp;
            }
        }
        if(a == 1)
            printf("Finite\n");
        else
            printf("Infinite\n");
    }
    return 0;
}
