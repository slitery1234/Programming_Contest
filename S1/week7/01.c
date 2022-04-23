#include <stdio.h>
#include <stdlib.h>

int main()
{

    unsigned long long int a,temp,ori_int,rev_int=0;
    char c;
    while(scanf("%lld",&a)!=EOF)
    {
        rev_int=0;
        //scanf("%d",&a);
        ori_int = a;
        while(a!=0)
        {
            temp = a%10;
            rev_int = rev_int*10+temp;
            a = a/10;
            //printf("%lld,%lld\n",ori_int,rev_int);
        }

        if(ori_int == rev_int)
            printf("YES\n");
        else
            printf("NO\n");

    }

    return 0;
}
