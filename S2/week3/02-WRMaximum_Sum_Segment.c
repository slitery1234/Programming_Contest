#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n_num;
    scanf("%d",&n_num);
    int num[n_num];
    int sum[n_num+1];
    int temp_sum=0;
    int max_sum=-2000000000,min_sum=2000000000;
    int max_i=0,min_i=0;

    for(int i=0; i<n_num; i++)
        scanf("%d",&num[i]);

    sum[0]=0;

    for(int i=0; i<n_num; i++)
    {
        temp_sum+=num[i];
        sum[i+1]=temp_sum;
        //printf("%d ",sum[i]);
    }

    for(int i=0; i<n_num+1; i++)
    {
        if(max_sum<sum[i])
        {
            max_i=i;
            max_sum=sum[i];
        }
        if(min_sum>sum[i])
        {
            min_i=i;
            min_sum=sum[i];
        }

    }
    int lmin_sum=2000000000,lmin_i=0;
    int rmax_sum=-2000000000,rmax_i=0;

    if(min_i>max_i)
    {
        for(int i=0;i<max_i+1;i++)
        {
            if(lmin_sum>sum[i])
            {
                lmin_i=i;
                lmin_sum=sum[i];
            }
        }
        for(int i=min_i;i<n_num+1;i++)
        {
            if(rmax_sum<sum[i])
            {
                rmax_i=i;
                rmax_sum=sum[i];
            }
        }

        if( (max_sum-lmin_sum) > (rmax_sum-min_sum) )
        {
            printf("%d %d\n",lmin_i+1,max_i);
            printf("%d",max_sum-lmin_sum);
        }
        else if( (max_sum-lmin_sum) == (rmax_sum-min_sum) )
        {
            int max_num=-10000;
            for(int i=0;i<n_num;i++)
            {
                if(max_num<num[i])
                {
                    max_num=num[i];
                    max_i=i;
                }
            }
            printf("%d %d\n",max_i+1,max_i+1);
            printf("%d",max_num);
        }
        else
        {
            printf("%d %d\n",min_i+1,rmax_i);
            printf("%d",rmax_sum-min_sum);
        }
    }
    else if(max_i==min_i)
    {
        printf("%d %d\n",min_i+1,max_i+1);
        printf("%d",num[min_i]);
    }
    else
    {
        printf("%d %d\n",min_i+1,max_i);
        printf("%d",max_sum-min_sum);
    }
    //printf("\n%d~%d\n%d~%d",lmin_sum,max_sum,min_sum,rmax_sum);


/*
    for(int i=0; i<n_num+1; i++)
    {
        if(i==0)
            sum[i]=0;
        else
        {
            temp_sum+=num[i-1];
            sum[i]=temp_sum;
            if(max_sum<sum[i])
            {
                max_sum=sum[i];
                max_i=i;
            }
        }
        if(min_sum>sum[i])
        {
            min_sum=sum[i];
            min_i=i+1;
        }
    }

    if(max_i<min_i)
    {
        min_sum=100000;
        for(int i=0; i<max_i; i++)
        {
            if(min_sum>sum[i])
            {
                min_sum=sum[i];
                min_i=i+1;
            }
        }
    }
    if(max_i==min_i)
    {
        for(int i=0; i<n_num; i++)
        {
            if( (max_sum-min_sum) < num[i])
            {
                max_sum=num[i];
                min_sum=0;
                max_i=i+1;
                min_i=i+1;
            }
        }
    }


    printf("%d %d\n",min_i,max_i);
    printf("%d",(max_sum-min_sum));

*/
    return 0;
}
