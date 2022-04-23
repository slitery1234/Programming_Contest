#include <stdio.h>
#include <stdlib.h>

int same_and_or(int a,int b,char c)
{
    if(c=='=')
    {
        if(a==b)
            return 1;
        else
            return 0;
    }
    else if(c=='!')
    {
        if(a==b)
            return 0;
        else
            return 1;
    }
    else if(c=='&')
    {
        if(a&&b)
            return 1;
        else
            return 0;
    }
    else if(c=='|')
    {
        if(a||b)
            return 1;
        else
            return 0;
    }
}

int math(int a,int b,char c)
{
    if(c == '+')
        return a+b;
    else if(c == '-')
        return a-b;
    else if(c == '*')
        return a*b;
    else if(c == '/')
        return a/b;
}

int if_else(int a,int b,int c)
{
    if(a)
        return b;
    else
        return c;
}

int array_left_move(int start,int new_start,int end,int type[],int integers[],char sy[])
{
    for(int i=0; i<(end-start+1); i++)
    {
        type[new_start+i]=type[start+i];
        if(type[new_start+i]==0)
            integers[new_start+i]=integers[start+i];
        else if(type[new_start+i]==1)
            sy[new_start+i]=sy[start+i];
    }
    return end - (start - new_start);
}

int eval_expr(int left,int right,int type[],int integers[],char symbols[][3])
{
    char sy[right+1];
    int l2[right+1];
    int temp=0;
    int l=0,r=0;
    int count=0;

    for(int i=0; i<=right; i++)
        sy[i]='\0';

    //存放符號

    for(int i=left; i<=right; i++)
    {
        if(type[i]==1)
            sy[i]=symbols[i][0];
    }

    /*
    for(int i=left; i<right+1; i++)
    {
        printf("%d:%c\n",i,sy[i]);
    }
    */


    //處理（）

    for(int i=left; i<right+1; i++)
    {
        if(type[i]==1)
        {
            if(sy[i]=='(')
                l=i;
            else if(sy[i]==')')
            {
                r=i;
                temp=eval_expr(l+1,r-1,type,integers,symbols);
                //printf("temp:%d\n",temp);
                type[l]=0;
                integers[l]=temp;
                right=array_left_move(r+1,l+1,right,type,integers,sy);
                i=left;
            }
        }
    }



    //處理 * /

    for(int i=left; i<right+1; i++)
    {
        if(type[i]==1)
        {
            if( sy[i]=='*'||sy[i]=='/')
            {
                l=i-1;
                r=i+1;
                temp=math(integers[l],integers[r],sy[i]);
                type[l]=0;
                integers[l]=temp;
                right=array_left_move(r+1,l+1,right,type,integers,sy);
                i=left;
            }
        }
    }

    //處理 + -
    for(int i=left; i<right+1; i++)
    {
        if(type[i]==1)
        {
            if( sy[i]=='+'||sy[i]=='-')
            {
                l=i-1;
                r=i+1;
                temp=math(integers[l],integers[r],sy[i]);
                type[l]=0;
                integers[l]=temp;
                //if(r+1<=right)
                right=array_left_move(r+1,l+1,right,type,integers,sy);

                i=left;
                /*else
                {
                    right -= (r-l);
                    i=left;
                }*/
            }
        }
    }

    //處理 == !=

    for(int i=left; i<right+1; i++)
    {
        if(type[i]==1)
        {
            if(sy[i]=='='||sy[i]=='!')
            {
                l=i-1;
                r=i+1;
                temp=same_and_or(integers[l],integers[r],sy[i]);
                type[l]=0;
                integers[l]=temp;
                right=array_left_move(r+1,l+1,right,type,integers,sy);
                i=left;
            }
        }
    }
    //處理 && ||
    for(int i=left; i<right+1; i++)
    {
        if(type[i]==1)
        {
            if(sy[i]=='&'||sy[i]=='|')
            {
                l=i-1;
                r=i+1;
                temp=same_and_or(integers[l],integers[r],sy[i]);
                type[l]=0;
                integers[l]=temp;
                right=array_left_move(r+1,l+1,right,type,integers,sy);
                i=left;
            }
        }
    }
    //處理 ? :


    for(int i=left; i<right+1; i++)
    {
        if(type[i]==1)
        {
            if(sy[i]=='?')
                l=i;
            else if(sy[i]==':')
            {
                temp=if_else(integers[l-1],integers[l+1],integers[l+3]);
                type[l-1]=0;
                integers[l-1]=temp;
                right=array_left_move(l+4,l,right,type,integers,sy);
                i=left;
            }
        }
    }


    if(right!=left)
        eval_expr(left,right,type,integers,symbols);
    else
        return integers[left];
}

int main()
{
    int type[13]= {0,1,0,1,0,1,0,1,1,0,1,0,1};
    int integers[13]= {3,0,2,0,0,0,32,0,0,2,0,3,0};
    char symbols[13][3];
    for(int i=0; i<13 ;i++)
    {
        if(i==1)
            symbols[i][0]='=';
        else if(i==3)
            symbols[i][0]='?';
        else if(i==5)
            symbols[i][0]=':';
        else if(i==7)
            symbols[i][0]='*';
        else if(i==8)
            symbols[i][0]='(';
        else if(i==10)
            symbols[i][0]='+';
        else if(i==12)
            symbols[i][0]=')';
        else
            symbols[i][0]='A';
    }

    int a = eval_expr(0,12,type,integers,symbols);
    printf("%d",a);
    return 0;
}
