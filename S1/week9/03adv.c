#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char str[100000]={0};
    int total=0,local_sum=0;
    fgets(str,100000,stdin);
    char *p;
    p=strlwr(str);
    char *token;

    for(int i=0;i<100000;i++)
    {
        if( str[i]>=48&&str[i]<=57 )
        {
            local_sum+=str[i]-48;
            if((i+1)<100000)
            {
                if( str[i+1]>=48&&str[i+1]<=57 )
                    local_sum*=10;
                else
                {
                    total+=local_sum;
                    local_sum=0;
                }
            }
            else
            {
                total+=local_sum;
                local_sum=0;
            }
        }
    }

    token=strtok(str," ,.\r\n");
    while(token!=NULL)
    {
        if(strstr(token,"one")!=NULL)
            total+=1;
        if(strstr(token,"two")!=NULL)
            total+=2;
        if(strstr(token,"three")!=NULL)
            total+=3;
        if(strstr(token,"four")!=NULL)
            total+=4;
        if(strstr(token,"five")!=NULL)
            total+=5;
        if(strstr(token,"six")!=NULL)
            total+=6;
        if(strstr(token,"seven")!=NULL)
            total+=7;
        if(strstr(token,"eight")!=NULL)
            total+=8;
        if(strstr(token,"nine")!=NULL)
            total+=9;
        if(strstr(token,"ten")!=NULL)
            total+=10;
        if(strstr(token,"twenty")!=NULL)
            total+=20;
        if(strstr(token,"thirty")!=NULL)
            total+=30;
        if(strstr(token,"forty")!=NULL)
            total+=40;
        if(strstr(token,"fifty")!=NULL)
            total+=50;
        if(strstr(token,"sixty")!=NULL)
            total+=60;
        if(strstr(token,"seventy")!=NULL)
            total+=70;
        if(strstr(token,"eighty")!=NULL)
            total+=80;
        if(strstr(token,"ninety")!=NULL)
            total+=90;
        token=strtok(NULL," ,.\r\n");
    }
    printf("%d",total);
}

