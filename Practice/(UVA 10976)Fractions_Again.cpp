//https://vjudge.net/problem/37234/origin

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int input;
    while(cin >> input)
    {
        pair<int,int> p;
        int a,b;
        vector< pair<int,int> > ans;

        for(int i=input+1;i<=2*input;i++)
        {
            a=i - input;
            b=input * i;
            if(b % a == 0)
            {
                p = make_pair(b/a ,i);
                ans.push_back(p);
            }
        }
        cout << ans.size() << "\n";
        for(int i=0;i<ans.size();i++)
            cout << "1/" << input << " = 1/" << ans[i].first
                 << " + 1/" << ans[i].second << "\n";
    }
    return 0;
}
