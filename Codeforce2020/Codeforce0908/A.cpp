#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nc;
    cin >> nc;
    for(int ni=0;ni<nc;ni++)
    {
        int n;
        cin >> n;
        int a[n];
        int odd = 0;
        int eve = 0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            if(a[i] == 1 && i%2 == 0)
                eve++;
            else if(a[i] == 1 && i%2 == 1)
                odd++;
        }
        if(eve == odd)
        {
            cout << n << "\n";
            for(int i=0;i<n;i++)
                cout << a[i] << " ";
            cout << "\n";
        }
        else
        {
            int flag = 0;
            vector<int> ans;
            if( (eve + odd) % 2 == 0 )
            {
                int cnt = abs((eve-odd)) /2 ;
                for(int i=0;i<n;i++)
                {
                    if(a[i] == 1 && flag == 0)
                        flag = 1;
                    else if(a[i] == 1 && flag == 1)
                        flag = 0;

                    if(a[i] == 0 && cnt > 0 && flag == 1)
                    {
                        cnt--;
                        continue;
                    }
                    ans.push_back(a[i]);
                }

            }
            else if( (eve + odd) % 2 == 1 )
            {
                vector<int> tmp;
                int flag = 0;
                for(int i=0;i<n;i++)
                {
                    if(a[i] == 1 && flag == 0)
                    {
                        flag = 1;
                        continue;
                    }
                    tmp.push_back(a[i]);
                }
                eve=0;
                odd=0;
                for(int i=0;i<tmp.size();i++)
                {
                    if(tmp[i] == 1 && i%2 == 0)
                        eve++;
                    else if(tmp[i] == 1 && i%2 == 1)
                        odd++;
                }

                int cnt = abs((eve-odd)) /2 ;
                for(int i=0;i<tmp.size();i++)
                {
                    if(a[i] == 1 && flag == 0)
                        flag = 1;
                    else if(a[i] == 1 && flag == 1)
                        flag = 0;

                    if(a[i] == 0 && cnt > 0 && flag == 1)
                    {
                        cnt--;
                        continue;
                    }
                    ans.push_back(tmp[i]);
                }
            }
            cout << ans.size() << "\n";
            for(int x:ans)
                cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}
