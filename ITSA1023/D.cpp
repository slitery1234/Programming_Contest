#include <bits/stdc++.h>
using namespace std;

int test(int a[8])
{
    int d[6];
    d[0] = (a[0]-a[2])*(a[0]-a[2])+(a[1]-a[3])*(a[1]-a[3]);
    d[1] = (a[0]-a[4])*(a[0]-a[4])+(a[1]-a[5])*(a[1]-a[5]);
    d[2] = (a[0]-a[6])*(a[0]-a[6])+(a[1]-a[7])*(a[1]-a[7]);
    d[3] = (a[2]-a[4])*(a[2]-a[4])+(a[3]-a[5])*(a[3]-a[5]);
    d[4] = (a[2]-a[6])*(a[2]-a[6])+(a[3]-a[7])*(a[3]-a[7]);
    d[5] = (a[4]-a[6])*(a[4]-a[6])+(a[5]-a[7])*(a[5]-a[7]);

    int temp = -1;
    int temp2 = 0;
    int ct = 0;
    for(int i=0; i<3; i++)
    {
        ct = 0;
        for(int j=i; j<6; j++)
        {
            if(d[j] == d[i])
            {
                ct++;
            }
            else
                temp2 = d[j];
        }
        if(ct >= 4)
        {
            temp = d[i];
            break;
        }
    }
    if(temp == -1)
        return 0;

    if(temp = temp2 / 2)
        return temp;
    else
        return 0;
}


int main()
{
    int m;
    cin >> m;
    int a[8];
    int b[8];
    for(int i=0; i<8; i++)
        cin >> a[i];
    for(int i=0; i<8; i++)
        cin >> b[i];

    int squa = test(a);
    int squb = test(b);

    if(squa != 0)
        printf("Yes %d\n",squa*m*m);
    else
        printf("No\n");
    if(squb != 0)
        printf("Yes %d\n",squb*m*m);
    else
        printf("No\n");

    if(squa == squb)
        printf("Peace\n");
    else if(squa > squb)
        printf("A\n");
    else if(squa < squb)
        printf("B\n");
    return 0;
}


