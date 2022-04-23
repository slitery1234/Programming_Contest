#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[30];
    while(fgets(input,30,stdin) != NULL)
    {
        int n=0;
        while(input[n]!='\n')
            n++;

        int a[n];
        for(int i=0;i<n;i++)
            a[i] = input[i] - '0';
        int length[n];
        int max_len=0,max_i=0;

        for(int i=0; i<n; i++)
            length[i]=1;

        for(int i=n-1; i>=0; i--)
        {
            max_i=0;
            max_len=0;
            for(int j=n-1; j>i; j--)
            {
                if(a[i]<a[j])
                {
                    if(max_len < length[j])
                    {
                        max_len=length[j];
                        max_i=j;
                    }
                }
            }
            length[i]=length[i]+max_len;
        }
        //--------------------------

        max_i=0;
        max_len=0;

        for(int i=0; i<n; i++)
        {
            if(max_len < length[i])
            {
                max_len=length[i];
                max_i=i;
            }
        }
        int t=max_len;
        int max_num=0;
        int last_i=0;
        for(int i=0; i<n; i++)
        {
            max_num=-1;
            for(int j=last_i; j<n; j++)
            {
                if(length[j] == t)
                {
                    if(a[j] > max_num)
                    {
                        max_num = a[j];
                        last_i = j;
                    }
                }
            }

            if(max_num != (-1))
            {
                printf("%d",max_num);
                t--;
            }

        }
        printf("\n");
    }

}
