#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);

    int t=0;
    while(!(n<10))
    {
        n++;
        t++;

        while(n % 10 == 0)
        {
            n/=10;
        }
    }
    t+=9;

    printf("%d\n",t);

    return 0;
}
