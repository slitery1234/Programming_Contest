#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str[300000]={0};
    int total=0,local_sum=0;
    int is_find=1;
    //fgets(str,300000,stdin);
    //cin.getline(str,100000,EOF);
    for(int i=0; i<300000; i++)
    {
        str[i]=getchar();
        if(str[i]==EOF)
            break;
        else if(str[i]>='A' && str[i]<='Z')
            str[i]+=32;
    }
    string same_as_str;
    same_as_str.assign(str);

    char *p;

    char *token;

    for(int i=0; i<300000; i++)
    {
        if(str[i]>=48&&str[i]<=57)
        {
            local_sum+=str[i]-48;
            if((i+1)<300000)
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


    string::size_type position_1=0;
    string::size_type position_2=0;
    string::size_type position_3=0;
    string::size_type position_4=0;
    string::size_type position_5=0;
    string::size_type position_6=0;
    string::size_type position_7=0;
    string::size_type position_8=0;
    string::size_type position_9=0;
    string::size_type position_10=0;
    string::size_type position_20=0;
    string::size_type position_30=0;
    string::size_type position_40=0;
    string::size_type position_50=0;
    string::size_type position_60=0;
    string::size_type position_70=0;
    string::size_type position_80=0;
    string::size_type position_90=0;

    string::size_type n_position_1=0;
    string::size_type n_position_2=0;
    string::size_type n_position_3=0;
    string::size_type n_position_4=0;
    string::size_type n_position_5=0;
    string::size_type n_position_6=0;
    string::size_type n_position_7=0;
    string::size_type n_position_8=0;
    string::size_type n_position_9=0;
    string::size_type n_position_10=0;
    string::size_type n_position_20=0;
    string::size_type n_position_30=0;
    string::size_type n_position_40=0;
    string::size_type n_position_50=0;
    string::size_type n_position_60=0;
    string::size_type n_position_70=0;
    string::size_type n_position_80=0;
    string::size_type n_position_90=0;

    while(is_find)
    {
        is_find=0;
        n_position_1=same_as_str.find("one",position_1);
        n_position_2=same_as_str.find("two",position_2);
        n_position_3=same_as_str.find("three",position_3);
        n_position_4=same_as_str.find("four",position_4);
        n_position_5=same_as_str.find("five",position_5);
        n_position_6=same_as_str.find("six",position_6);
        n_position_7=same_as_str.find("seven",position_7);
        n_position_8=same_as_str.find("eight",position_8);
        n_position_9=same_as_str.find("nine",position_9);

        n_position_10=same_as_str.find("ten",position_10);
        n_position_20=same_as_str.find("twenty",position_20);
        n_position_30=same_as_str.find("thirty",position_30);
        n_position_40=same_as_str.find("forty",position_40);
        n_position_50=same_as_str.find("fifty",position_50);
        n_position_60=same_as_str.find("sixty",position_60);
        n_position_70=same_as_str.find("seventy",position_70);
        n_position_80=same_as_str.find("eighty",position_80);
        n_position_90=same_as_str.find("ninety",position_90);

        if(n_position_1!=string::npos)
        {
            total+=1;
            position_1=n_position_1+1;
            is_find=1;
        }
        if(n_position_2!=string::npos)
        {
            total+=2;
            position_2=n_position_2+1;
            is_find=1;
        }
        if(n_position_3!=string::npos)
        {
            total+=3;
            position_3=n_position_3+1;
            is_find=1;
        }
        if(n_position_4!=string::npos)
        {
            total+=4;
            position_4=n_position_4+1;
            is_find=1;
        }
        if(n_position_5!=string::npos)
        {
            total+=5;
            position_5=n_position_5+1;
            is_find=1;
        }
        if(n_position_6!=string::npos)
        {
            total+=6;
            position_6=n_position_6+1;
            is_find=1;
        }
        if(n_position_7!=string::npos)
        {
            total+=7;
            position_7=n_position_7+1;
            is_find=1;
        }
        if(n_position_8!=string::npos)
        {
            total+=8;
            position_8=n_position_8+1;
            is_find=1;
        }
        if(n_position_9!=string::npos)
        {
            total+=9;
            position_9=n_position_9+1;
            is_find=1;
        }
        if(n_position_10!=string::npos)
        {
            total+=10;
            position_10=n_position_10+1;
            is_find=1;
        }
        if(n_position_20!=string::npos)
        {
            total+=20;
            position_20=n_position_20+1;
            is_find=1;
        }
        if(n_position_30!=string::npos)
        {
            total+=30;
            position_30=n_position_30+1;
            is_find=1;
        }
        if(n_position_40!=string::npos)
        {
            total+=40;
            position_40=n_position_40+1;
            is_find=1;
        }
        if(n_position_50!=string::npos)
        {
            total+=50;
            position_50=n_position_50+1;
            is_find=1;
        }
        if(n_position_60!=string::npos)
        {
            total+=60;
            position_60=n_position_60+1;
            is_find=1;
        }
        if(n_position_70!=string::npos)
        {
            total+=70;
            position_70=n_position_70+1;
            is_find=1;
        }
        if(n_position_80!=string::npos)
        {
            total+=80;
            position_80=n_position_80+1;
            is_find=1;
        }
        if(n_position_90!=string::npos)
        {
            total+=90;
            position_90=n_position_90+1;
            is_find=1;
        }
    }


    printf("%d",total);
}
