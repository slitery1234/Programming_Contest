#include <bits/stdc++.h>
using namespace std;

void firstline(char c)
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
void secondline(char c)
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
void thirdline(char c)
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
void fourthline(char c)
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
void fifthline(char c)
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
string itoa(long long int n)
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
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> s;
        long long int a = atoi(s.c_str());
        cin >> s;
        char c = s[0];
        cin >> s;
        long long int b = atoi(s.c_str());

        long long int ans = 0;
        if(c == '+')
            ans = a+b;
        else if(c == '-')
            ans = a-b;
        else if(c == '*')
            ans = a*b;

        s = itoa(a) + c + itoa(b) + "=" + itoa(ans);

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

