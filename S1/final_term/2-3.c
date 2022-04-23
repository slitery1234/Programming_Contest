#include <stdio.h>
#include <stdlib.h>

char my_buffer;
int is_my_buffer_filled=0;

char my_getchar()
{
    char c='\0';
    if(is_my_buffer_filled == 0)
        return getchar();
    else
    {
        c=my_buffer;
        my_buffer='\0';
        is_my_buffer_filled=0;
        return c;
    }
}
void my_buffer_fill( char ch )
{
    my_buffer=ch;
    is_my_buffer_filled=1;
}

int read_expr( int type[], int integers[], char symbols[][3])
{
    char x,y;
    int i=0;
    int num=0;
    while ((x = my_getchar()) !=EOF)
    {
        y=my_getchar();
        if(x>='0'&&x<='9')
        {
            if(y>='0'&&y<='9')
            {
                num*=10;
                num+=(x-'0');
            }
            else
            {
                num*=10;
                num+=(x-'0');
                type[i]=0;
                integers[i]=num;
                num=0;
                i++;
            }
            my_buffer_fill(y);
        }
        else if (x=='&'||x=='='||x=='|'||x=='!')
        {
            type[i]=1;
            symbols[i][0]=x;
            if(x!='!')
            {
                symbols[i][1]=x;
                symbols[i][2]='\0';
            }
            else
            {
                symbols[i][1]='=';
                symbols[i][2]='\0';
            }
            i++;
        }
        else if (x=='+'||x=='-'||x=='*'||x=='/'||x=='('||x==')'||x=='?'||x==':')
        {
            type[i]=1;
            symbols[i][0]=x;
            symbols[i][1]='\0';
            my_buffer_fill(y);
            i++;
        }
        else if (x==';')
        {
            type[i]=1;
            symbols[i][0]=x;
            symbols[i][1]='\0';
            my_buffer_fill(y);
            i++;
            return i;
        }
        else
        {
            my_buffer_fill(y);
        }
    }
    return i;
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


int main()
{
    int token_count;
    int type[1000], integers[1000];
    char symbols[1000][3];

    while( token_count = read_expr(type, integers, symbols) )
    {
        int left=0;
        int right=token_count;
            char sy[right+1];
        int l2[right+1];
        int temp=0;
        int l=0,r=0;
        int count=0;

        for(int i=0; i<=right; i++)
            sy[i]='\0';

        for(int i=left; i<=right; i++)
        {
            if(type[i]==1)
                sy[i]=symbols[i][0];
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

                    right=array_left_move(r+1,l+1,right,type,integers,sy);
                    i=left;
                }
            }
        }

        printf("%d",integers[0]
    }

    return 0;
}
