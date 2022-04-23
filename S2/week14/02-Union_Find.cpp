#include <bits/stdc++.h>
using namespace std;

struct link
{
    int index;
    int parent;
};

int find_i(link union_set[],int i)
{
    if(union_set[i].parent != i)
        union_set[i].parent = find_i(union_set,union_set[i].parent);
    return union_set[i].parent;
}
void union_ab(link union_set[],int a,int b)
{
    int a_root = find_i(union_set ,a);
    int b_root = find_i(union_set ,b);

    if(a_root == b_root)
        return;

    if(rand() % 2 == 0)
    {
        int temp = a_root;
        a_root = b_root;
        b_root = temp;
    }

    union_set[b_root].parent = a_root;

    return;
}
int check_ab(link union_set[],int a,int b)
{
    int a_root = find_i(union_set ,a);
    int b_root = find_i(union_set ,b);


    if(a_root == b_root)
        return 1;
    else
        return 0;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    link union_set[n];
    for(int i=0;i<n;i++)
    {
        union_set[i].index = i;
        union_set[i].parent = i;
    }
    char command;

    int x,y;

    for(int i=0;i<m;i++)
    {
        scanf("%c",&command);
        while(command != 'm' && command != '?')
            scanf("%c",&command);

        scanf("%d%d",&x,&y);
        if(command == 'm')
            union_ab(union_set,x-1,y-1);
        else if(command == '?')
        {
            int ans = check_ab(union_set,x-1,y-1);
            if(ans == 1)
                printf("Y\n");
            else
                printf("N\n");
        }
    }

    return 0;
}
