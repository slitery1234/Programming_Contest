#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0;
    scanf("%d",&n);
    int n2=n,count=0;
    for(int i=2;i<n2;i++)
    {
        if(n%i==0)
        {
            n/=i;
            count+=1;
            if(n%i==0)
                i--;
            else
            {
                printf("%d ^ %d\n",i,count);
                count=0;
            }
        }
        if(i>n)
            break;
    }
    return 0;
}
