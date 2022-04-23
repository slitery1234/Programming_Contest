//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1415

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    int tim=1;
    cin >> n >> q;
    while (!(n==0 && q==0))
    {
        cout << "CASE# " << tim << ":\n";
        int a[n];
        int qq,found=0;
        for(int j=0;j<n;j++)
            cin >> a[j];
        sort(a,a+n);
        for(int i=0;i<q;i++)
        {
            found = 0;
            cin >> qq;
            for(int j=0;j<n;j++)
            {
                if(qq == a[j])
                {
                    cout << qq << " found at " << j+1 << "\n";
                    found = 1;
                    break;
                }
            }
            if(found == 0)
                cout << qq << " not found\n";
        }
        cin >> n >> q;
        tim++;
    }

    return 0;
}
