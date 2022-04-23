#include<stdio.h>
int table[1000001];
int sum(int a)
{
    int ans=1;
    while(a>0)
    {
        if(a%10)
        {
            ans=ans*(a%10);
        }
        a=a/10;
    }
    return ans;
}
int build(int i)
{
    if(i<10)
    {
        return table[i]=i;
    }
    else
    {
        int s=sum(i);
        return table[i]=table[s];

    }
}
int main()
{
    int array[1000001][9];
    for(int i=0; i<=1000000; i++)
    {
        build(i);
        //printf("%d :%d\n",i,table[i]);

        for(int j=0; j<9; j++)
        {
            if(i)
            {
                if(table[i]==j+1)
                    array[i][j]=array[i-1][j]+1;
                else
                    array[i][j]=array[i-1][j];
            }
            else
            {
                array[i][j]=0;
            }

            //printf("%d ",array[i][j]);
        }
        //printf("\n");
        //printf(" finish :%d\n",i);
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        printf("%d\n",array[b][c-1]-array[a-1][c-1]);
    }
}
