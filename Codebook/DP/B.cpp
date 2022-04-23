#include <iostream>
#include <cstring>
using namespace std;

struct coin
{
    int val;
    int wei;
};

int main()
{
    int nc;
    cin >> nc;
    for(int ni=0;ni<nc;ni++)
    {
        int a,b;
        cin >> a >> b;
        int w = b-a;
        int n;
        cin >> n;
        coin ip[n];
        for(int i=0;i<n;i++)
            cin >> ip[i].val >> ip[i].wei;

        int ans[w+1];
        memset(ans,0x3f3f3f3f,sizeof(ans));
        ans[0] = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=ip[i].wei;j<=w;j++)
            {
                ans[j] = min(ans[j],ans[j-ip[i].wei] + ip[i].val);
            }
        }

        if(ans[w] == 0x3f3f3f3f)
            cout << "This is impossible.\n";
        else
            cout << "The minimum amount of money in the piggy-bank is " << ans[w] << ".\n";
    }
    return 0;
}
