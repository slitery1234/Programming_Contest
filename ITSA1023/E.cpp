#include <bits/stdc++.h>
using namespace std;

int main()
{
    string ip;
    getline(cin,ip);
    int m = atoi(ip.c_str());

    for(int ni=0;ni<m;ni++)
    {
        string s1;
        getline(cin,s1);
        string s2="";
        string ans="";
        string num="";
        int type = 0;
        int tmp = 0;
        for(int i=0;i<=s1.size();i++)
        {
            if(s1[i] >= 'A' && s1[i] <= 'Z')
                s2 += s1[i];
            if(s1[i] >= '0' && s1[i] <= '9')
            {
                num += s1[i];
                type = 1;
            }
            if(type == 1 && (s1[i] == '\0' || s1[i] == ' ' ))
            {
                int n = atoi(num.c_str());
                for(int j=0;j<s2.size();j++)
                {
                    char tc = s2[j] + n;
                    if(tc > 'Z')
                        tc -= 26;
                    ans += tc;
                }
                s2 = "";
                num = "";
                type = 0;
            }
            else if(s1[i] == '\0')
            {
                ans += s2;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}



