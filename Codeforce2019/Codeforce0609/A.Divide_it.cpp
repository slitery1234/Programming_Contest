#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        long long int x;
        int ans=0;
        cin >> x;

        while(x % 5 == 0)
        {
            x/=5;
            x*=4;
            ans++;
        }
        while(x % 3 == 0)
        {
            x/=3;
            x*=2;
            ans++;
        }
        while(x % 2 == 0)
        {
            x/=2;
            ans++;
        }

        if(x == 1)
            printf("%d\n",ans);
        else
            printf("-1\n");
    }



    return 0;
}
