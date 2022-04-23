#include <stdio.h>

int execute(int index,int g,int b,int th)
{
    int killed = index + th -1;
    int n = g+b;
    if(killed > n)
        killed = killed %n;
    if(killed == 0)
        killed = n;
    if(killed > g)
    {
        if(b > 1)
            return execute(killed,g,b-1,th);
        else
            return 1;
    }
    else
        return 0;
}

int main()
{
    int n;
    scanf("%d",&n);

    int ans[15];
    int t=1;
    for(int i=1;i<5000000;i++)
    {
        if(execute(1,t,t,i))
        {
            ans[t] = i;
            i=0;
            t++;
        }
        if(t == 14)
            break;
    }
    while(n!=0)
    {
        printf("%d\n",ans[n]);
        scanf("%d",&n);
    }
    return 0;
}
