//https://vjudge.net/problem/27946/origin

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int t=1;
    while(cin >> n)
    {
        int input;
        vector<int> v;
        long long temp = 1;
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            cin >> input;
            v.push_back(input);
        }

        for(int i=0;i<n;i++)
        {
            temp = 1;
            for(int j=i;j<n;j++)
            {
                temp *= v[j];
                if(ans < temp)
                    ans = temp;
            }
        }
        //if( (n == 1) && (v[0] < 0) )
            //cout << "Case #" << t << ": The maximum product is " << v[0] << ".\n";
        //else
            cout << "Case #" << t << ": The maximum product is " << ans << ".\n";
        t++;
        printf("\n");
    }
    return 0;
}

