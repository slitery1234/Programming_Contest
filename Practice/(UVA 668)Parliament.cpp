//https://vjudge.net/problem/35738/origin0

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int input;
    for(int ii=0;ii<n;ii++)
    {
        int sum=0,i=0;
        cin >> input;
        while(sum + (2+i) <= input)
        {
            sum += (2+i);
            i++;
        }
        int left = input - sum;
        int ans[i];

        for(int j=0;j<i;j++)
            ans[j] = 2+j;

        while(left>0)
        {
            for(int j=0;j<i;j++)
            {
                ans[i-1-j]++;
                left --;
                if(left == 0)
                    break;
            }

        }

        for(int j=0;j<i;j++)
        {
            cout << ans[j];
            if(j != i-1)
                cout << " ";
        }
        cout << "\n";
        if(ii != n-1)
            cout << "\n";
    }

    return 0;
}
