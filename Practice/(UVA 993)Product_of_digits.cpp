//https://vjudge.net/problem/19515/origin

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n_c;
    cin >> n_c;
    for(int n_i=0; n_i<n_c; n_i++)
    {
        int a[10];
        int n;
        cin >> n;
        for(int i=0; i<10; i++)
            a[i]=0;
        if(n == 1)
            cout << "1";
        else
        {
            for(int i=9; i>=2; i--)
            {
                while(n % i == 0)
                {
                    n/=i;
                    a[i]++;
                }
            }


            if(n == 1)
            {
                for(int i=2; i<=9; i++)
                {
                    while(a[i]!=0)
                    {
                        cout << i;
                        a[i]--;
                    }
                }
            }
            else
                cout << "-1";
        }
        cout << "\n";
    }
    return 0;
}
