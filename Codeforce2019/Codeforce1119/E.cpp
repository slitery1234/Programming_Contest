#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    long long int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

    if(n == 1 && a[0] == 1)
        cout << "-1\n";
    else
    {
        long long int sum = 0;
        for(int i=0; i<n; i++)
            sum += a[i];
        map<long long int,long long int> m;
        vector<long long int> prime;

        for(int i=2; i<=(int)sqrt(sum) ; i++)
        {
            if(sum % i == 0)
            {
                m.insert(make_pair(i,1));
                prime.push_back(i);
                sum = sum/i;
            }
            while(sum % i == 0)
            {
                m[i] = m[i]+1;
                sum = sum/i;
            }
        }
    }

    return 0;
}
