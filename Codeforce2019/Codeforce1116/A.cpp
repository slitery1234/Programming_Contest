#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nc;
    cin >> nc;
    for(int ni=0;ni<nc;ni++)
    {
        int n;
        cin >> n;
        int a[n],b[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<n;i++)
            cin >> b[i];

        int temp = 0;
        int l=-1,r=n;
        for(int i=0;i<n;i++)
        {
            if(a[i] > b[i])
            {
                temp = -1;
                break;
            }
            else if(a[i] < b[i])
            {
                temp = b[i]-a[i];
                l = i;
                break;
            }
        }

        if(l != -1)
        {
            for(int i=l;i<n;i++)
            {
                if(b[i] - a[i] != temp)
                {
                    r = i;
                    break;
                }
            }
            for(int i=r;i<n;i++)
            {
                if(a[i] != b[i])
                    temp = -1;
            }
        }
        if(temp == -1)
            printf("NO\n");
        else
            printf("YES\n");


    }
    return 0;
}
