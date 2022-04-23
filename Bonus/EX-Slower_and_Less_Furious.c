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

    int n_ans=0;
    scanf("%d",&n_ans);
    int loc[n_ans];
    for(int i=0;i<n_ans;i++)
        scanf("%d",&loc[i]);

    int vec[col];
    int ans[row];
    for(int c=0;c<col;c++)
        vec[c]=0;
    for(int r=0;r<row;r++)
        ans[r]=0;
    for(int i=0;i<n_ans;i++)
        vec[loc[i]-1]=1;

/*
    for(int c=0; c<col; c++)
    {
        printf("%d ",vec[c]);
    }
    printf("\n\n");
*/
    for(int i=0; i<n_ans; i++)
    {
        if(vec[ loc[i]-1 ] == 1)
        {

            for(int r=0;r<row;r++)
            {
                if(space[r][loc[i]-1] == 1 && vec[loc[i]-1] == 1)
                {
                    ans[r]=1;
                    for(int c=0;c<col;c++)
                    {
                        vec[c] = (vec[c] + space[r][c])%2;
                    }
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
    for(int c=0; c<col; c++)
    {
        printf("%d ",vec[c]);
    }
    printf("\n");
*/
    int has_ans=0;
    for(int r=0; r<row; r++)
    {
        if(ans[r]!=0)
        {
            printf("%d ",r+1);
            has_ans++;
        }
    }
    if(has_ans == 0)
        printf("Farewell, Dom.");
}
