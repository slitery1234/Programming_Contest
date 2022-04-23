#include <stdio.h>

int leng[10004];
int main()
{
    for(int i=1;i<=10000;i++)
    {
        int ti=i;
        int x=1;
        while(ti != 1)
        {
            if(ti % 2 ==1)
                ti = 3*ti+1;
            else
                ti = ti/2;
            x++;
        }
        leng[i] = x;
    }
    int l,r;
    while(scanf("%d %d",&l,&r) != EOF)
    {
        int max = 0;

        for(int i=l;i<=r;i++)
        {
            if(leng[i] > max)
                max = leng[i];
        }
        printf("%d %d %d\n",l,r,max);
    }
    return 0;
}
