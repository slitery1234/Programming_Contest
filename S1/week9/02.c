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

int main()
{
    char x,y,z;
    int fin=0;
    while ((x = my_getchar()) !=EOF)
    {
        y=my_getchar();

        if(x==' '||x=='\t'||x=='\n'||x=='\r')
        {
            //my_buffer_fill(y);
        }
        else if( (x>=33&&x<=47) || (x>=58&&x<=64) || (x>=91&&x<=94) || (x>=123&&x<=126) || x==96)
        {
            putchar(x);
            putchar('\n');
            //my_buffer_fill(y);
        }
        else if(x>=48&&x<=57)
        {
            putchar(x);
            if(fin==0)
            {
                if(!(y>=48&&y<=57))
                    putchar('\n');
            }
            else
            {
                if( (y>=48&&y<=57) || y=='_' || (y>=65&&y<=90) || (y>=97&&y<=122))
                {
                    //my_buffer_fill(y);
                }
                else
                {
                    fin=0;
                    putchar('\"');
                    putchar('\n');
                    //my_buffer_fill(y);x

                }
            }
            //my_buffer_fill(y);
        }
        else if (x=='_' || (x>=65&&x<=90) || (x>=97&&x<=122))
        {
            if(fin==0)
            {
                putchar('\"');
                fin=1;
            }
            putchar(x);

            if( (y>=48&&y<=57) || y=='_' || (y>=65&&y<=90) || (y>=97&&y<=122))
            {
                //my_buffer_fill(y);
            }
            else
            {
                fin=0;
                putchar('\"');
                putchar('\n');
                //my_buffer_fill(y);
            }
        }
        //else
            //my_buffer_fill(y);
        my_buffer_fill(y);
    }

    return 0;
}
