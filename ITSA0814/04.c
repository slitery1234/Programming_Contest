#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b)
{
      int c = *(int *)a;
      int d = *(int *)b;
      if(c < d)
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
        int a,b;
        scanf("%d%d",&a,&b);
        int c[a];
        for(int i=0;i<a;i++)
            scanf("%d",c[i]);
        qsort(c,a,sizeof(int),compare);

    }
    return 0;
}
