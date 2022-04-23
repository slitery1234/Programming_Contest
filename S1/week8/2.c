#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    char cal;

    while(scanf("%d",&a)!=EOF)
    {
        scanf(" %c %d",&cal,&b);
        if(cal=='+')
            printf("%d\n",a+b);
        else if(cal=='-')
            printf("%d\n",a-b);
        else if(cal=='*')
            printf("%d\n",a*b);
    }

    return 0;
}
