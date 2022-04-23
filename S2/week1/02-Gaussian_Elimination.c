#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row=0,col=0;
    scanf("%d%d",&col,&row);
    int s[row][col];

    for(int j=0; j<row; j++)
    {
        for(int i=0; i<col; i++)
        {
            scanf("%d",&s[j][i]);
        }
    }

    int move=0;

    for(int i=0; i<col; i++)
    {
        int tag=-1;
        int temp=0;

        for(int j=i-move; j<row; j++)
        {
            if(s[j][i]==1&&tag==-1)
            {
                tag=j;
            }
            else if(s[j][i]==1)
            {
                for(int k=0; k<col; k++)
                {
                    s[j][k] = (s[j][k] + s[tag][k])%2;
                }
            }
        }
        if(tag!=-1)
        {
            for(int k=0; k<col; k++)
            {
                temp=s[tag][k];
                s[tag][k]=s[i-move][k];
                s[i-move][k]=temp;
            }
        }
        else
        {
            if(i+move<row)
            move++;
        }

    }
    int ans=row;
    //printf("\n");
    for(int i=0;i<row;i++)
    {
        int sum=0;
        for(int j=0;j<col;j++)
        {
            sum+=s[i][j];
          // printf("%d",s[i][j]);
        }
      // printf("\n");
        if(sum==0)
            ans--;
    }
    printf("%d",ans);
}
