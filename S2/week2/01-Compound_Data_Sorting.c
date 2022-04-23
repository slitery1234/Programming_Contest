#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct data
    {
        char name[100];
        int age;
        int weight;
    };
    int n=0;
    scanf("%d",&n);
    struct data person[n];

    char name[100];
    int age=0;
    int weight=0;
    int s[n];

    for(int i=0; i<n; i++)
    {
        s[i]=i;
        scanf("%s %d %d",&name,&age,&weight);
        strcpy(person[i].name,name);
        person[i].age=age;
        person[i].weight=weight;
    }


    int compare(const void *a, const void *b)
    {
        int r=strcmp(person[*(int*)a].name,person[*(int*)b].name);
        if(r!=0)
            return r;
        else
        {
            int c = person[*(int*)a].age;
            int d = person[*(int*)b].age;
            if(c!=d)
                return (d-c);
            else
            {
                int e = person[*(int*)a].weight;
                int f = person[*(int*)b].weight;
                return (f-e);
            }
        }
    }
    qsort(s,n,sizeof(int),compare);


    for(int i=0; i<n; i++)
    {
        printf("%s %d %d\n",person[s[i]].name,person[s[i]].age,person[s[i]].weight);
    }
}
