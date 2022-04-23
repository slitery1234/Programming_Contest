#include <iostream>
using namespace std;

int n,m;

struct item
{
    int value;
    int weight;
};

int main()
{
    cin >> n >> m;
    int ans[m+1];

    item ip[n];
    for(int i=0;i<=m;i++)
        ans[i]=0;
    for(int i=0;i<n;i++)
        cin >> ip[i].weight >> ip[i].value;

    for(int i=0;i<n;i++)
    {
        for(int j=m;j>=ip[i].weight;j--)
        {
            ans[j] = max(ans[j] , ans[j-ip[i].weight]+ip[i].value);
        }
    }
    cout << ans[m] << "\n";
    return 0;
}
