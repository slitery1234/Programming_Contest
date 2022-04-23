//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1756

#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<string> s;
    string input_st;
    string st;

    while(cin >> input_st)
    {
        st = "";
        for(int i=0;i<input_st.size();i++)
        {
            if(input_st[i] >= 'A' && input_st[i] <= 'Z')
            {
                input_st[i] -= 'A';
                input_st[i] += 'a';
                st += input_st[i];
            }
            else if(input_st[i] >= 'a' && input_st[i] <= 'z')
            {
                st += input_st[i];
            }
            else
            {
                if(st != "")
                    s.insert(st);
                st="";
            }
        }
        if(st != "")
            s.insert(st);
    }
    vector<string> v;
    for(auto x:s)
        v.push_back(x);

    sort(v.begin(),v.end());

    for(auto x:s)
        cout << x << "\n";
    return 0;
}
