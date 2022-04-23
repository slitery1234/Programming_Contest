#include <stdio.h>
#include <stdlib.h>

char my_buffer;
int is_my_buffer_filled=0;

char my_getchar()
{
    char c=0;
    if(is_my_buffer_filled == 0)
        return getchar();
    else
    {
        c=my_buffer;
        my_buffer=0;
        is_my_buffer_filled=0;
        return c;
    }
}
void my_buffer_fill( char ch )
{
        my_buffer=ch;
        is_my_buffer_filled=1;
}
