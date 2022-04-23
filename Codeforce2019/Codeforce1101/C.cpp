#include <bits/stdc++.h>
using namespace std;

int stair(int i)
{
    if(i == 1 || i == 2)
        return i;
    else
        return stair(i-1) + stair(i-2);
}

int main()
{
    long long int x[100020];
    x[1] = 1;
    x[2] = 2;
    for(int i=3;i<100020;i++)
    {
        x[i] = x[i-1] + x[i-2];
        if(x[i] > 1000000007)
            x[i] -= 1000000007;
    }

    string s;
    cin >> s;
    char c = '\0';
    long long int ans = 1;
    int ct = 0;
    for(int i=0; s[i]!='\0'; i++)
    {
        if(s[i] == 'm' || s[i] == 'w')
        {
            ans = 0;
            break;
        }
        if(ct != 0 && c == s[i])
        {
            if(s[i] == 'n' || s[i] == 'u')
            {
                ct ++;
            }
        }
        else if(ct == 0)
        {
            if(s[i] == 'n' || s[i] == 'u')
            {
                ct ++;
            }
        }
        else
        {
            ans *= x[ct];
            ans %= 1000000007;
            ct = 0;
            i--;
        }
        c = s[i];
    }
    if(ct != 0)
    {
        ans *= x[ct];
        ans %= 1000000007;
        ct = 0;
    }
    cout << ans << "\n";
    return 0;
}
