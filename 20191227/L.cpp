#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h,n,k;
    cin >> h >> n >> k;
    int dp[h+1];
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    for(int i=1;i<n;i++)
        arr[i] += arr[i-1];
    for(int i=0;i<=h;i++)
        dp[i] = 1e9;
    dp[0] = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=h-arr[i];j++)
        {
            dp[j+arr[i]] = min(dp[j]+1, dp[j+arr[i]]);
        }
    }
    cout << dp[h] << "\n";
}
