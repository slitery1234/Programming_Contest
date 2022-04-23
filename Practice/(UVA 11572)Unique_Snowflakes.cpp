#include <bits/stdc++.h>
using namespace std;

int input[2000000];

int main()
{
    int n_c;
    cin >> n_c;

    for(int n_i=0;n_i<n_c;n_i++)
    {
        int n;
        cin >> n;
        int ans=0;
        set<int> s;
        for(int i=0;i<n;i++)
        {
            cin >> input[i];
        }
        int left_bound=0;
        for(int i=0;i<n;i++)
        {
            if(s.count(input[i]) == 1)
            {
                for(int j=left_bound;j<i;j++)
                {
                    if(input[j] != input[i])
                        s.erase( s.find(input[j]) );
                    else
                    {
                        left_bound = j+1;
                        break;
                    }
                }
            }

            s.insert(input[i]);

/*
            cout << s.size() << " ";
            for(auto x:s)
                cout << x <<" ";
            cout << "\n";
*/

            if (s.size() > ans)
                ans = s.size();
        }

        cout << ans << "\n" ;
    }
    return 0;
}
