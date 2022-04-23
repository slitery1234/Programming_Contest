#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
void make_friend(int n,char name[][21],int is_friend[][n],char name1[],char name2[])
{
    int name1_tag=-1;
    int name2_tag=-1;

    for(int i=0; i<n; i++)
    {
        if( (strcmp(name[i],name1)) == 0 )
            name1_tag = i;
        else if( (strcmp(name[i],name2)) == 0 )
            name2_tag = i;
    }

    is_friend[name1_tag][name2_tag] = 1;
    is_friend[name2_tag][name1_tag] = 1;
    return;
}


void list_friend(int n,char name[][21],int is_friend[][n],char name1[])
{
    int name1_tag=-1;
    for(int i=0; i<n; i++)
    {
        if( (strcmp(name[i],name1)) == 0 )
        {
            name1_tag = i;
            i=n;
        }
    }

    for(int i=0; i<n; i++)
    {
        if( is_friend[name1_tag][i] == 1 )
        {
            printf("%s ",name[i]);
        }
    }
    printf("\n");
    return;
}*/
int main()
{/*
    int n;
    scanf("%d",&n);
    char name[n][21];
    int is_friend[n][n];
    for(int i=0; i<n; i++)
        scanf("%s",&name[i]);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            is_friend[i][j]=0;
        }
    }

    char command[10];
    char name1[21],name2[21];
    int n2;
    scanf("%d",&n2);

    int num=n;      //不太清楚為甚麼n會在進迴圈時被清掉= =

    for(int i=0; i<n2; i++)
    {
        scanf("%s",&command);
        if( (strcmp(command,"MakeFriend")) == 0 )
        {
            scanf(" %s %s",&name1,&name2);
            make_friend(num,name,is_friend,name1,name2);
        }
        else if( (strcmp(command,"ListFriend")) == 0 )
        {
            scanf(" %s",&name1);
            list_friend(num,name,is_friend,name1);
        }
    }
    return 0;*/
}

