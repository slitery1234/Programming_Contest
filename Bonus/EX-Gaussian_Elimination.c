#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int pre_row,int new_row,int col,float space[][col])
{
    float temp;
    for(int i=0; i<col; i++)
    {
        temp=space[pre_row][i];
        space[pre_row][i]=space[new_row][i];
        space[new_row][i]=temp;
    }
}

void plus(int ori_row,int tar_row,int col,float space[][col],float tar_c)
{
    for(int i=0; i<col; i++)
    {
        space[tar_row][i]=(space[tar_row][i] - space[ori_row][i]*tar_c);
    }
}


void times(int tar_row,float t,int col,float space[][col])
{
    for(int i=0; i<col; i++)
    {
        space[tar_row][i]=(space[tar_row][i] / t);
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int n_variable;
    scanf("%d",&n_variable);
    char variable[n_variable][10];
    for(int i=0; i<n_variable; i++)
        scanf("%s",&variable[i]);
    int n_equation;
    scanf("%d",&n_equation);
    int n_item;

    int row=n_variable;
    int col=n_variable+1;
    float space[row][col];

    for(int j=0; j<row; j++)
    {
        for(int k=0; k<col; k++)
            space[j][k]=0;
    }

    float temp_i;
    char temp_v[10];
    int is_vari;

    for(int i=0; i<n_equation; i++)
    {
        scanf("%d",&n_item);
        for(int j=0; j<n_item; j++)
        {
            is_vari=0;
            temp_i=0;
            temp_v[0]='\0';
            scanf("%f",&temp_i);
            scanf("%[a-z]",&temp_v);
            for(int k=0; k<n_variable; k++)
            {
                if(strcmp(variable[k],temp_v) == 0)       //if variable[k] = scanf %s
                {
                    space[i][k]=temp_i;
                    is_vari=1;
                }
            }
            if(is_vari == 0)                    //is constant
                space[i][col-1]=temp_i;

            /*
            if(is_vari !=0)
                printf("%f%s ",temp_i,temp_v);
            else
                printf("%f ",temp_i);*/
        }


    }


    for(int i=0; i<row; i++)
    {
        for(int r=i; r<row; r++)
        {
            for(int c=0; c<col; c++)
            {
                if(space[r][c]>=0.000001 || space[r][c]<=-0.000001)
                {
                    swap(r,i,col,space);    //swap r and i
                    times(i,space[i][c],col,space); // change to 1
                    for(int r2=i+1; r2<row; r2++)
                    {
                        if(space[r2][c]>=0.000001 || space[r2][c]<=-0.000001)
                        {
                            if(space[i][c]>0)
                                plus(i,r2,col,space,space[r2][c]);
                            else
                                plus(i,r2,col,space,-space[r2][c]);
                        }
                    }
                    r=row+1;
                    c=col+1;
                }
            }
        }
    }
    for(int r=row-1; r>=0; r--)
    {
        for(int c=col-2; c>=0; c--)
        {
            if(space[r][c]-1<0.000001 && space[r][c]-1>-0.000001)
            {
                for(int r2=r-1; r2>=0; r2--)
                {
                    if(space[r2][c]>=0.000001 || space[r2][c]<=-0.000001)
                    {
                        plus(r,r2,col,space,space[r2][c]);
                    }
                }
                c=-1;
            }
        }
    }
/*
    for(int j=0; j<row; j++)
    {
        for(int k=0; k<col; k++)
            printf("%f ",space[j][k]);
        printf("\n");
    }
*/
    float ans[n_variable];
    int have_solution[n_variable];  //0:one sol,1:infinity sol,-1:no sol

    for(int k=0; k<n_variable; k++)
    {
        ans[k]=0;
        have_solution[k]=0;
    }

    for(int r=0; r<row; r++)
    {
        int c=0;
        for(c=0; c<col-1; c++)
        {
            if(space[r][c]-1<0.000001 && space[r][c]-1>-0.000001)
            {
                ans[r]=-space[r][col-1];
                c=col;
            }
        }

        if(c==col-1)
        {
            if(space[r][col-1] <0.000001 && space[r][col-1] >-0.000001)
                have_solution[r]=1;
            else
                have_solution[r]=-1;
        }
    }

    int get_answer = 0;

    for(int k=0; k<n_variable; k++)
    {
        if(have_solution[k] == -1)
        {
            get_answer = -1;
            printf("INFEASIBLE");
            k=n_variable;
        }
        else if(have_solution[k] == 1)
        {
            get_answer ++;
        }
    }

    if(get_answer > 0)
    {
        printf("INFINITE\n");
        for(int r=row-1-get_answer; r>=0; r--)
        {
            for(int c=col-2-get_answer; c>=0; c--)
            {
                if(space[r][c]-1<0.000001 && space[r][c]-1>-0.000001)
                {
                    for(int r2=r-1; r2>=0; r2--)
                    {
                        if(space[r2][c]>=0.000001 || space[r2][c]<=-0.000001)
                        {
                            plus(r,r2,col,space,space[r2][c]);
                        }
                    }
                    c=-1;
                }
            }
        }

        for(int i=0;i<(n_variable-get_answer);i++)
        {
            printf("%s %d ",variable[i],1+get_answer);
            for(int j=0;j<get_answer;j++)
            {
                printf("%f%s ",-space[i][n_variable-j-1],variable[n_variable-j-1]);
            }
            printf("%f\n",-space[i][col-1]);
        }
        for(int i=(n_variable-get_answer);i<n_variable;i++)
        {
            printf("%s free\n",variable[i]);
        }

    }
    else if(get_answer == 0)
    {
        printf("UNIQUE\n");
        for(int i=0; i<n_variable; i++)
            printf("%s 1 %f\n",variable[i],ans[i]);
    }



    return 0;
}
