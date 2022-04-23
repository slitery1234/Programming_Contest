#include <stdio.h>
#include <stdlib.h>

void swap(int pre_row,int new_row,int col,int space[][col])
{
    int temp;
    for(int i=0; i<col; i++)
    {
        temp=space[pre_row][i];
        space[pre_row][i]=space[new_row][i];
        space[new_row][i]=temp;
    }
}

void plus(int ori_row,int tar_row,int col,int space[][col])
{
    for(int i=0; i<col; i++)
    {
        space[tar_row][i]=(space[tar_row][i] + space[ori_row][i]) % 2;
    }
}

int main()
{
    int row,col;
    scanf("%d%d",&col,&row);
    int space[row][col];
    for(int r=0; r<row; r++)
    {
        for(int c=0; c<col; c++)
            scanf("%d",&space[r][c]);
    }


    for(int i=0; i<row; i++)
    {
        for(int r=i; r<row; r++)
        {
            for(int c=0; c<col; c++)
            {
                if(space[r][c]==1)
                {
                    swap(r,i,col,space);    //ец┤л

                    for(int r2=i+1; r2<row; r2++)
                    {
                        if(space[r2][c]==1)
                        {
                            plus(i,r2,col,space);   //м█е[
                        }
                    }
                    r=row+1;
                    c=col+1;
                }
            }
        }
    }
/*
    for(int r=0; r<row; r++)
    {
        for(int c=0; c<col; c++)
        {
            printf("%d ",space[r][c]);
        }
        printf("\n");
    }
*/
    int ntest;
    int vec[col];
    int is_zero=0;
    scanf("%d",&ntest);
    for(int i=0; i<ntest; i++)
    {
        for(int c=0; c<col; c++)
            scanf("%d",&vec[c]);

        for(int c=0; c<col; c++)
        {
            if(vec[c]==1)
            {
                for(int r=row-1; r>=0; r--)
                {
                    if(space[r][c]==1)
                    {
                        for(int c2=0; c2<col; c2++)
                        {
                            vec[c2] = (vec[c2]+space[r][c2]) % 2;
                        }
                        r=-1;
                    }
                }
            }
        }

        is_zero=0;

        for(int c=0; c<col; c++)
            is_zero+=vec[c];
        if(is_zero == 0)
            printf("Yes\n");
        else
            printf("No\n");

    }


}
