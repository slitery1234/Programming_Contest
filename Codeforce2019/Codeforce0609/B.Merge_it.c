#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        int n2;
        scanf("%d",&n2);
        int arr[3];
        for(int j=0;j<3;j++)
            arr[j] = 0;
        int x;
        for(int j=0;j<n2;j++)
        {
            scanf("%d",&x);
            arr[(x%3)] ++;
        }
        int ans = arr[0];

        if(arr [2] > arr[1])
        {
            ans += arr[1];
            arr[2] -= arr[1];
            ans += arr[2]/3;
        }
        else if(arr [1] > arr[2])
        {
            ans += arr[2];
            arr[1] -= arr[2];
            ans += arr[1]/3;
        }
        else if(arr [1] = arr[2])
        {
            ans += arr[2];
        }


        printf("%d\n",ans);

    }



    return 0;
}
