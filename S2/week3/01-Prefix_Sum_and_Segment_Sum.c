#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n_num,n_time;
    scanf("%d %d",&n_num,&n_time);
    int num[n_num];
    int sum[n_num+1];
    sum[0]=0;
    int temp_sum=0;
    int start,end;
    for(int i=0;i<n_num;i++)
        scanf("%d",&num[i]);

    for(int i=0;i<n_num;i++)
    {
        temp_sum+=num[i];
        sum[i+1]=temp_sum;
        //printf("%d ",sum[i]);
    }
    //printf("%d \n",sum[n_num]);


    for(int i=0;i<n_time;i++)
    {
        scanf("%d %d",&start,&end);
        start-=1;
        printf("%d\n",(sum[end]-sum[start]));
    }


    return 0;
}
