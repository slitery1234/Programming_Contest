#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row,col;
    scanf("%d%d",&col,&row);
    int space[row][col];
    int temp;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            scanf("%d",&space[i][j]);
    }

    /*
    printf("\n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d",space[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    */
    int row_sum=0;

    for(int c=0; c<col; c++)
    {
        for(int r=c; r<row; r++)
        {
            if(space[r][c]==1)
            {
                for(int c2=0; c2<col; c2++)
                {
                    temp=space[r][c2];
                    space[r][c2]=space[c][c2];
                    space[c][c2]=temp;
                }
                r=row;  //²×¤îr°j°é
            }
        }
        for(int r=c+1; r<row; r++)
        {

            if(space[r][c]==1)
            {
                for(int c2=0; c2<col; c2++)
                {
                    space[r][c2] = (space[r][c2]+space[c][c2])%2;
                }
            }
        }

    }

    int exist_vec=0;
    for(int i=0; i<row; i++)
    {
        int sum=0;
        for(int j=0; j<col; j++)
        {
            sum+=space[i][j];
           // printf("%d",space[i][j]);
        }
        //printf("\n");
        if(sum!=0)
            exist_vec++;
    }
   // printf("%d",exist_vec);

    for(int i=exist_vec-1;i>0;i--)
    {
        for(int r=0;r<i;r++)
        {
            if(space[r][i]==1&&space[i][i]==1)
            {
                for(int c=0;c<col;c++)
                {
                    space[r][c]=(space[r][c]+space[i][c])%2;
                }
            }
        }
    }

    //printf("\n\n");
    exist_vec=0;
    for(int i=0; i<row; i++)
    {
        int sum=0;
        for(int j=0; j<col; j++)
        {
            sum+=space[i][j];
            //printf("%d",space[i][j]);
        }
        //printf("\n");
        if(sum!=0)
            exist_vec++;
    }
    printf("%d",exist_vec);



}
