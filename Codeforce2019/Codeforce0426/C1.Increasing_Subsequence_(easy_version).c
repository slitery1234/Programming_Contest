#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);

    int t=0,now_i=0;
    char x[n];
    int l_item=0,r_item=0;
    int left=0,right=n-1;


    while(left+l_item <= right-r_item)
    {

        if(l_item==0 && r_item==0)
        {

            if(a[left+l_item] < a[right-r_item])
            {
                if(a[left+l_item] > now_i)
                {
                    x[t]='L';
                    now_i=a[left+l_item];
                    t++;
                    left++;
                    //printf("%d L %d/%d/%d\n",t,left,l_item,now_i);
                }
                else
                {
                    l_item++;
                }
            }
            else if (a[left+l_item] > a[right-r_item])
            {
                if(a[right-r_item] > now_i)
                {
                    x[t]='R';
                    now_i=a[right-r_item];
                    t++;
                    right--;
                    //printf("%d R %d/%d/%d\n",t,right,r_item,now_i);
                }
                else
                {
                    r_item++;
                }
            }
            else
            {
                if( left+l_item == right-r_item)
                {
                    x[t]='R';
                    now_i=a[right-r_item];
                    t++;
                    right--;
                }
                else
                {
                    l_item++;
                }
            }
        }
        else if(l_item!=0 && r_item!=0)
            break;
        else
        {
            if(l_item == 0)
            {
                if(a[left+l_item] > now_i)
                {
                    x[t]='L';
                    now_i=a[left+l_item];
                    t++;
                    left++;
                    //printf("%d L %d/%d/%d\n",t,left,l_item,now_i);
                }
                else
                {
                    l_item++;
                }
            }
            else if(r_item == 0)
            {
                if(a[right-r_item] > now_i)
                {
                    x[t]='R';
                    now_i=a[right-r_item];
                    t++;
                    right--;
                    //printf("%d R %d/%d/%d\n",t,right,r_item,now_i);
                }
                else
                {
                    r_item++;
                }
            }
        }
    }



    printf("%d\n",t);
    for(int i=0; i<t; i++)
    {
        printf("%c",x[i]);
    }


    return 0;
}
