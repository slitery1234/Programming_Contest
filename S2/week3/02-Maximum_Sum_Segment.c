#include <stdio.h>
#include <stdlib.h>

int main()
{
    //freopen("Sample.in.txt", "r", stdin);

    int n;
    scanf("%d",&n);
    int a[n+1];
    int sum[n+1];
    a[0]=0;
    sum[0]=0;
    int temp_sum=0;
    int max_i=0,min_i=0;
    int max_sum=0,min_sum=0;
    int ans_li=0,ans_ri=0;
    int ans_sum=0;


    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        temp_sum+=a[i];
        sum[i]=temp_sum;
    }
    temp_sum=0;
    for(int i=0;i<=n;i++)
    {
        if(a[i]>0)
        {
            max_sum = sum[i];
            max_i = i;
            temp_sum+=a[i];
        }
        else if(a[i]<0)
        {
            if( (temp_sum + a[i]) <0)
            {
                min_sum = sum[i];
                min_i = i;
                temp_sum=0;
            }
            else
            {
                max_sum = sum[i];
                max_i = i;
                temp_sum+=a[i];
            }
        }

        if(max_i>min_i)
        {
            if(max_sum-min_sum>ans_sum)
            {
                ans_li=min_i+1;
                ans_ri=max_i;
                ans_sum=max_sum-min_sum;
            }
        }
    }
    if((ans_li==0) && (ans_ri==0))
    {
        int max_num=a[1];
        ans_li=1;
        ans_ri=1;
        ans_sum=a[1];

        for(int i=1;i<=n;i++)
        {
            if(max_num < a[i])
            {
                ans_li=i;
                ans_ri=i;
                ans_sum=a[i];
            }
        }
    }

    printf("%d %d\n%d",ans_li,ans_ri,ans_sum);

    return 0;
}
