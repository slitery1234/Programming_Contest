#include <bits/stdc++.h>
using namespace std;
void firstline(int c)
{
    if(c == '0' || c == '2' || c == '3' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' )
        cout << ".*****.";
    else if(c == '1')
        cout << ".***...";
    else if(c == '4' || c == '*')
        cout << ".*...*.";
    else if(c == '+')
        cout << "...*...";
    else if(c == '-' || c == '=')
        cout << ".......";
}
void secondline(int c)
{
    if(c == '0' || c == '4' || c == '7' || c == '8' || c == '9' )
        cout << ".*...*.";
    else if(c == '1' || c == '+')
        cout << "...*...";
    else if(c == '2' || c == '3')
        cout << ".....*.";
    else if(c == '5' || c == '6')
        cout << ".*.....";
    else if(c == '-' )
        cout << ".......";
    else if(c == '*' )
        cout << "..*.*..";
    else if(c == '=' )
        cout << ".*****.";
}
void thirdline(int c)
{
    if(c == '0' || c == '7')
        cout << ".*...*.";
    else if(c == '1' )
        cout << "...*...";
    else if(c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '8' || c == '9' || c == '+' || c == '-')
        cout << ".*****.";
    else if(c == '*' )
        cout << "...*...";
    else if(c == '=' )
        cout << ".......";
}
void fourthline(int c)
{
    if(c == '0' || c == '6' || c == '8')
        cout << ".*...*.";
    else if(c == '1' || c == '+')
        cout << "...*...";
    else if(c == '2' )
        cout << ".*.....";
    else if(c == '3' || c == '4' || c == '5' || c == '7' || c == '9')
        cout << ".....*.";
    else if(c == '-' )
        cout << ".......";
    else if(c == '*' )
        cout << "..*.*..";
    else if(c == '=' )
        cout << ".*****.";
}
void fifthline(int c)
{
    if(c == '0' || c == '1' || c == '2' || c == '3' || c == '5'|| c == '6'|| c == '8'|| c == '9')
        cout << ".*****.";
    else if(c == '4'|| c == '7')
        cout << ".....*.";
    else if(c == '+' )
        cout << "...*...";
    else if(c == '-' || c == '=')
        cout << ".......";
    else if(c == '*' )
        cout << ".*...*.";
}
string itoa(int n)
{
    string s="";
    string s2;
    if(n < 0)
    {
        s2 += "-";
        n*=-1;
    }
    else if(n == 0)
        return "0";

    while(n!=0)
    {
        s += (n%10)+'0';
        n/=10;
    }
    for(int i=s.size()-1; i>=0; i--)
        s2 += s[i];
    return s2;
}

int main()
{
    int n;
    string s;
    getline(cin,s);
    n = atoi(s.c_str());
    for(int i=0; i<n; i++)
    {
        getline(cin,s);

        string t= "";
        stack<string> st;
        int istimes = 0;
        for(int j=0; j<s.size(); j++)
        {
            if(s[j] == ' ')
            {
                if(istimes == 1)
                    istimes = 2;
                else if(istimes == 2)
                {
                    int xx = atoi(st.top().c_str());
                    st.pop();
                    xx = xx * atoi(t.c_str());
                    st.push(itoa(xx));
                    istimes = 0;
                    t = "";
                    continue;
                }
                if(t != "")
                {
                    st.push(t);
                    t = "";
                }
            }
            else if(s[j] == '*')
                istimes = 1;
            else
                t += s[j];
        }
        if(t != "")
        {
            if(istimes == 2)
            {
                int xx = atoi(st.top().c_str());
                st.pop();
                xx = xx * atoi(t.c_str());
                st.push(itoa(xx));
                istimes = 0;
                t = "";
            }
            else
            {
                st.push(t);
                t = "";
            }
        }
        int sz = st.size();
        string arr[sz];

        for(int j=sz-1; j>=0; j--)
        {
            arr[j] = st.top();
            st.pop();
        }

        int ans = atoi(arr[0].c_str());

        for(int j=1; j<sz; j++)
        {
            if(arr[j][0] == '+')
            {
                j++;
                ans += atoi(arr[j].c_str());
            }
            else if(arr[j][0] == '-')
            {
                j++;
                ans -= atoi(arr[j].c_str());
            }
        }

        s = s + "=" + itoa(ans);

        for(int j=0; j<s.size(); j++)
            firstline(s[j]);
        cout << "\n";
        for(int j=0; j<s.size(); j++)
            secondline(s[j]);
        cout << "\n";
        for(int j=0; j<s.size(); j++)
            thirdline(s[j]);
        cout << "\n";
        for(int j=0; j<s.size(); j++)
            fourthline(s[j]);
        cout << "\n";
        for(int j=0; j<s.size(); j++)
            fifthline(s[j]);
        cout << "\n";
    }
}

