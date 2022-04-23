#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m=0,n=0;
    scanf("%d%d",&m,&n);
    int i=0,j=0;
    for(i=-2;i<=m+1;i++)
    {
        if(i==-2 || i==0 || i==(m+1))
        {
            printf("+-----+");
            for(j=1;j<=n;j++)
                printf("----");
            printf("--+");
        }
        else if(i==-1)
        {
            printf("|     |");
            for(j=1;j<=n;j++)
                printf("%4d",j);
            printf("  |");
        }
        else
        {
            printf("|  %d  |",i);
            for(j=1;j<=n;j++)
                printf("%4d",i*j);
            printf("  |");
        }
        printf("\n");
    }
    return 0;
}
