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

int array_left_move(int start,int new_start,int end,int type[],int integers[],char sy[],char symbols[][3])
{
    for(int i=0; i<(end-start+1); i++)
    {
        type[new_start+i]=type[start+i];
        if(type[new_start+i]==0)
            integers[new_start+i]=integers[start+i];
        else if(type[new_start+i]==1)
        {
            sy[new_start+i]=sy[start+i];
            symbols[new_start+i][0]=symbols[start+i][0];
        }
    }
    return end - (start - new_start);
}

int eval_expr(int left,int right,int type[],int integers[],char symbols[][3])
{
    char sy[right+1];
    int l2[right+1];
    int l=0,r=0;
    int temp=0;
    int count=0;

    for(int i=0; i<=right; i++)
        sy[i]='\0';

    //存放符號

    for(int i=left; i<=right; i++)
    {
        if(type[i]==1)
            sy[i]=symbols[i][0];
    }


    /*for(int c=0; c<100; c++)
    {
        if(type[c]==1)
            printf("sy[%d]=%c\n",c,sy[c]);
    }*/

    //處理（）

    int l_parentheses[right+1],r_parentheses[right+1];
    int count_of_parentheses=-1; //括號數量
    int distance=1000;
    int nearest=0;

    for(int i=0; i<=right; i++)
    {
        l_parentheses[i]=0;
        r_parentheses[i]=0;
    }

    //編號（）

    for(int i=left; i<right+1; i++)
    {
        if(type[i]==1)
        {
            if(sy[i]=='(')
            {
                count_of_parentheses++;
                l_parentheses[count_of_parentheses]=i;
            }
            else if(sy[i]==')')
            {
                for(int j=0; j<=count_of_parentheses; j++)
                {
                    if(r_parentheses[j]==0)
                    {
                        if(i-l_parentheses[j]<distance)
                        {
                            distance=i-l_parentheses[j];
                            nearest=j;
                        }
                    }
                }
                r_parentheses[nearest]=i;
                distance=1000;
            }

            /*              as example
            算式            ((8*2)+((3+9)+3))
            括號編號        01   1 23   3  20
            位置                      1111111
                            01234567890123456
            結論            => l[0]=0,r[0]=16
                            => l[1]=1,r[1]=5
                            => l[2]=7,r[2]=15
                            => l[3]=8,r[3]=12
            */
        }
    }

    //實際計算
    int left_moved=0;
    for(int i=count_of_parentheses; i>=0; i--)
    {
        temp=eval_expr(l_parentheses[i]+1,r_parentheses[i]-1,type,integers,symbols);
        type[l_parentheses[i]]=0;
        integers[l_parentheses[i]]=temp;

        left_moved=right;
        right=array_left_move(r_parentheses[i]+1,l_parentheses[i]+1,right,type,integers,sy,symbols);
        left_moved=left_moved-right;

        for(int j=0; j<=i; j++)
        {
            if(r_parentheses[j]>r_parentheses[i])
                r_parentheses[j]-=left_moved;
        }
    }
    /*              as example
    算式            ((2*2)+((1+1)+3))
    括號編號        01   1 23   3  20
    位置                      1111111
                    01234567890123456
    結論            => l[0]=0,r[0]=16
                    => l[1]=1,r[1]=5
                    => l[2]=7,r[2]=15
                    => l[3]=8,r[3]=12
    i=3時
                              1111111
                    01234567890123456
                    ((2*2)+(2    +3))
    move            ((2*2)+(2+3))
    結論            => l[0]=0,r[0]=16-(16-12)=16-4=12
                    => l[1]=1,r[1]=5
                    => l[2]=7,r[2]=15-(16-12)=15-4=11
    i=2時
                              1111111
                    01234567890123456
    move            ((2*2)+5    )
                    ((2*2)+5)
    結論            => l[0]=0,r[0]=12-(12-8)=12-4=8
                    => l[1]=1,r[1]=5
    i=1時
                              1111111
                    01234567890123456
    move            (4    +5)
                    (4+5)
    結論            => l[0]=0,r[0]=8-(8-4)=8-4=4
    i=0時
                              1111111
                    01234567890123456
    move            (9  )
                    9
    */



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
                right=array_left_move(r+1,l+1,right,type,integers,sy,symbols);
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

                right=array_left_move(r+1,l+1,right,type,integers,sy,symbols);
                i=left;
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
                right=array_left_move(r+1,l+1,right,type,integers,sy,symbols);
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
                right=array_left_move(r+1,l+1,right,type,integers,sy,symbols);
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
                right=array_left_move(l+4,l,right,type,integers,sy,symbols);
                i=left;
            }
        }
    }


    /*if(right!=left)
        eval_expr(left,right,type,integers,symbols);
    else*/
    return integers[left];
}


int main()
{
    int token_count;
    int type[1000], integers[1000];
    char symbols[1000][3];
    for(int i=0; i<1000; i++)
    {
        type[i]=-1;
        integers[i]=0;
        symbols[i][0]='\0';
    }

    while( token_count = read_expr(type, integers, symbols) )
    {
        eval_expr(0,token_count,type,integers,symbols);
        printf("%d\n",integers[0]);
        for(int i=0; i<1000; i++)
        {
            type[i]=-1;
            integers[i]=0;
            symbols[i][0]='\0';
        }
    }
    return 0;
}

/*
偷看算式用
for(int c=0; c<(right+1); c++)
{
    if(type[c]==0)
        printf("%d",integers[c]);
    else
    {
        printf("%c",sy[c]);
        if(sy[c]==';')
            break;
    }
}
*/
