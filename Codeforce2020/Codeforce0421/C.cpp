#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nc;
    cin >> nc;
    for(int ni=0; ni<nc; ni++)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++)
            cin >> a[i];
        vector<int> pos,neg;
        int maxx = 0;
        int minn = -2147000000;
        for(int i=0; i<n; i++)
        {
            if(a[i] > 0)
            {
                if(minn != -2147000000)
                {
                    neg.push_back(minn);
                    minn = -2147000000;
                }
                if(a[i] > maxx)
                    maxx = a[i];
            }
            else if(a[i] < 0)
            {
                if(maxx != 0)
                {
                    pos.push_back(maxx);
                    maxx = 0;
                }
                if(a[i] > minn)
                    minn = a[i];
            }
        }
        if(minn != -2147000000)
            neg.push_back(minn);
        if(maxx != 0)
            pos.push_back(maxx);

        long long int sum = 0;
        for(int i=0; i<pos.size(); i++)
            sum += pos[i];
        for(int i=0; i<neg.size(); i++)
            sum += neg[i];


        cout << sum << "\n";
    }

    return 0;
}
