#include <stdio.h>
#include <stdlib.h>



int gcd ( int a, int b )
{
    int temp;
    if(b==0)
        return a;
    else if(a<b)
        return gcd (b,a);
    else
    {
        a=a%b;
        return gcd (b,a);
    }
}
