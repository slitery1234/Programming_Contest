#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=0,b=0;
    char c;

    while( scanf("%d %c %d",&a,&c,&b) != EOF)
    {
        if(c=='+')
            printf("%d\n",a+b);
        else if(c=='-')
            printf("%d\n",a-b);
        else if(c=='*')
            printf("%d\n",a*b);
    }

    return 0;
}
