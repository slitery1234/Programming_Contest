#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[6][n/6];
    int a[6];

    for(int i=0; i<6; i++)
        a[i] = 0;

    int x;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);

        if(x == 4 && a[0] < n/6)
        {
            arr[0][a[0]] = i;
            a[0] ++;
        }
        else if(x == 8 && a[1] < n/6)
        {
            arr[1][a[1]] = i;
            a[1] ++;
        }
        else if(x == 15 && a[2] < n/6)
        {
            arr[2][a[2]] = i;
            a[2] ++;
        }
        else if(x == 16 && a[3] < n/6)
        {
            arr[3][a[3]] = i;
            a[3] ++;
        }
        else if(x == 23 && a[4] < n/6)
        {
            arr[4][a[4]] = i;
            a[4] ++;
        }
        else if(x == 42 && a[5] < n/6)
        {
            arr[5][a[5]] = i;
            a[5] ++;
            int posi = arr[5][a[5]];

            for(int j1=a[4]-1; j1>=0; j1--)
            {
                if(arr[4][j1] < posi)
                {
                    posi = arr[4][j1];

                    for(int j2=a[3]-1; j2>=0; j2--)
                    {
                        if(arr[3][j2] < posi)
                        {
                            posi = arr[3][j2];
                            for(int j3=a[2]-1; j3>=0; j3--)
                            {
                                if(arr[2][j3] < posi)
                                {
                                    posi = arr[2][j3];
                                    for(int j4=a[1]-1; j4>=0; j4--)
                                    {
                                        if(arr[1][j4] < posi)
                                        {
                                            posi = arr[1][j4];
                                            for(int j5=a[0]-1; j5>=0; j5--)
                                            {
                                                if(arr[0][j5] < posi)
                                                {
                                                    for(int k=0;k<6;k++)
                                                        a[k]--;
                                                    for(int k=j5;k<a[0]-2;k++)
                                                        arr[0][k]=arr[0][k+1];
                                                    for(int k=j4;k<a[3]-2;k++)
                                                        arr[1][k]=arr[1][k+1];
                                                    for(int k=j3;k<a[0]-2;k++)
                                                        arr[2][k]=arr[2][k+1];
                                                    for(int k=j2;k<a[0]-2;k++)
                                                        arr[3][k]=arr[3][k+1];
                                                    for(int k=j1;k<a[0]-2;k++)
                                                        arr[4][k]=arr[4][k+1];
                                                    break;
                                                }
                                            }
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }

                            break;
                        }
                    }

                    break;
                }
            }

        }
    }
    int ans = 0;
    for(int i=0;i<6;i++)
    {
        ans += a[i];
    }
    printf("%d",ans);

    return 0;
}
