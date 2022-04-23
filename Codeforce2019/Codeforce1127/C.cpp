#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nc;
    cin >> nc;
    for(int ni=0; ni<nc; ni++)
    {
        unsigned long long int r,b,k;
        cin >> r >> b >> k;
        unsigned long long int kr=0,kb=0;
        unsigned long long int  tr=1,tb=1;
        int last;
        if(r < b)
        {
            last = 1;
            kb = 1;
        }
        else
        {
            last = 0;
            kr = 1;
        }

        while(kb < k && kr < k)
        {
            if(r * tr < b * tb)
            {
                if(last == 0)
                    kr+= (b*tb) / (r*tr) - (!((b*tb)%(r*tr)));
                else
                {
                    kb=0;
                    kr+= (b*tb) / (r*tr) - (!((b*tb)%(r*tr)));
                    last = 0;
                }
                tr+= (b*tb) / (r*tr) - (!((b*tb)%(r*tr)));
            }
            else if(r * tr > b * tb)
            {
                if(last == 1)
                    kb+= (r*tr) / (b*tb) - (!((r*tr)%(b*tb)));
                else
                {
                    kr = 0;
                    kb+= (r*tr) / (b*tb) - (!((r*tr)%(b*tb)));
                    last = 1;
                }
                tb+= (r*tr) / (b*tb) - (!((r*tr)%(b*tb)));
            }
            else
                break;
        }
        if(kb >= k || kr >= k)
            cout << "REBEL\n";
        else
            cout << "OBEY\n";
    }
    return 0;
}
