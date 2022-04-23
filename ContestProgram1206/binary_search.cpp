#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    for(int i=0;i<m;i++)
    {
        int temp;
        cin >> temp;
        int* index = lower_bound(arr,arr+n,temp);
        if(*index == temp)
            cout << index - arr + 1 << "\n";
        else
            cout << "Not found!\n";
    }
    return 0;
}
