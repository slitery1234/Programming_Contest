#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,q;
    string s;
    cin >> n >> m >> q;
    getline(cin,s);
    set<string> sign,frie;

    for(int i=0; i<n; i++)
    {
        getline(cin,s);
        sign.insert(s);
    }

    getline(cin,s);
    string t = "";
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == ' ')
        {
            frie.insert(t);
            t="";
        }
        else
            t+=s[i];
    }
    if(t != "")
        frie.insert(t);

    int ans = 0;
    t = "";

    getline(cin,s);
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == ' ')
        {
            if(sign.count(t) == 0)
            {
                ans = 1;
                break;
            }
            else if(frie.count(t) == 1)
            {
                ans = 2;
            }
            t = "";
        }
        else
            t+=s[i];
    }
    if(t != "")
    {
        if(sign.count(t) == 0)
            ans = 1;
        else if(frie.count(t) == 1)
            ans = 2;
        else
            t == "";
    }


    if(ans == 0)
        cout << "Safe\n";
    else if(ans == 2)
        cout << "Cheat\n";
    else if(ans == 1)
        cout << "Teacher is Blind !\n";
}
