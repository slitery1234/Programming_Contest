#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    getline(cin,s);
    n = atoi(s.c_str());
    for(int i=0; i<n; i++)
    {
        stack<int> st;
        getline(cin,s);
        while(s[0] == '\0')
            getline(cin,s);
        string t = "";
        for(int j=0; j<s.size(); j++)
        {
            if(s[j] >= '0' && s[j] <= '9')
                t = t + s[j];
            if(s[j] == ' ')
            {
                st.push(atoi(t.c_str()));
                t = "";
            }
        }
        if(t != "")
        {
            st.push(atoi(t.c_str()));
            t = "";
        }
        while(st.size()>1)
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << "\n";
    }
}
