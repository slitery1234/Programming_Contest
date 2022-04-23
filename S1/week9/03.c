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
    char x,y;
    int i=0;
    int num=0,total=0;
    while ((x = my_getchar()) !=EOF)
    {
        y=my_getchar();

        if(x>=48&&x<=57)
        {
            if(y>=48&&y<=57)
            {
                num*=10;
                num+=(x-48);
            }
            else
            {
                num*=10;
                num+=(x-48);
                total+=num;
                num=0;
            }
            //total+=(x-48);
            /*if(y==EOF)
                break;*/
        }

        my_buffer_fill(y);
        i++;
        //printf("%d: x=%c,y=%c,num=%d\n",i,x,y,num);

    }
    printf("%d",total);
    return 0;
}
