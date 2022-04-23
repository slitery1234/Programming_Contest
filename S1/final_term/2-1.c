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
