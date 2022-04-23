#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b)
{
      int c = *(int *)a;
      int d = *(int *)b;
      if(c > d)
        return -1;
      else if(c == d)
        return 0;
      else
        return 1;
}

int main()
{
    int nc;
    scanf("%d",&nc);
    for(int nci=0;nci<nc;nci++)
    {
        int a;
        int ans = 0;
        scanf("%d",&a);
        int mon[a];
        float x[a];

        for(int i=0;i<a;i++)
            x[i] = (float)i/(float)a;

        /*for(int i=0;i<=a;i++)
            printf("%.2f ",x[i]);*/

        for(int i=0;i<a;i++)
            scanf("%d",&mon[i]);

        qsort(mon,a,sizeof(int),compare);


        for(int i=0;i<a;i++)
        {
            int rep=0;
            for(int j=i;j<a-1;j++)
            {
                if(mon[j+1] == mon[j])
                    rep++;
                else
                    break;
            }
            for(int j=0;j<rep;j++)
            {
                x[i+j+1] = x[i];
            }

            if( x[i] <= 0.1)
            {
                if( (mon[i]*4) % 10 !=0)
                    ans += mon[i]*4/10+1;
                else
                    ans += mon[i]*4/10;
            }
            else if( x[i] <= 0.3)
            {
                if( (mon[i]*3) % 10 !=0)
                    ans += mon[i]*3/10+1;
                else
                    ans += mon[i]*3/10;
            }
            else if( x[i] <= 0.6)
            {
                if( (mon[i]*2) % 10 !=0)
                    ans += mon[i]*2/10+1;
                else
                    ans += mon[i]*2/10;
            }
            else if( x[i] <= 0.8)
            {
                if( (mon[i]*1) % 10 !=0)
                    ans += mon[i]*1/10+1;
                else
                    ans += mon[i]*1/10;
            }
        }

        /*for(int i=0;i<=a;i++)
            printf("%.2f ",x[i]);*/
        printf("%d\n",ans);

    }
    return 0;
}

