#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n;
    scanf("%d",&n);

    int age[n],hei[n],wei[n];
    int index_age[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d",&age[i],&hei[i],&wei[i]);
        index_age[i]=i;
    }

    //qsort�Ψ禡------------------------
    int compare(const void *a, const void *b)
    {
        int c = age[*(int *)a];
        int d = age[*(int *)b];
        // #2--------
        if(c==d)
        {
            c = wei[*(int *)a];
            d = wei[*(int *)b];
            return (d-c);
        }
        else
        //-----------
            return (c-d);
    }
    //-----------------------------------

    qsort(index_age,n,sizeof(index_age[0]),compare);

    for(int i=0; i<n; i++)
    {
        printf("%d %d %d\n",age[index_age[i]],hei[index_age[i]],wei[index_age[i]]);
    }
}
