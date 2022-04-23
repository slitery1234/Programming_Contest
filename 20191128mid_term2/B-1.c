#include <stdio.h>

int check(int n,int a[],int ch[],int i)
{
    if(i == 0)
        return 1;
    if(a[i/2-(!(i%2))] > a[i])
        return 0;
    return ch[i/2-(!(i%2))];
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],ch[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        ch[i] = check(n,a,ch,i);
        if(ch[i] == 0)
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
