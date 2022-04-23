#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ncase;
    scanf("%d",&ncase);
    int a,b,c,count=0,max_count=0;;
    for(int i=0;i<2*ncase;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(b==0)
        {
            count+=1;
            if(max_count<count)
                max_count=count;
        }
        else
            count-=1;
    }
    printf("%d",max_count);
    return 0;
}
