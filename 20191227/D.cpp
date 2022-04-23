#include <bits/stdc++.h>
using namespace std;

void strpl(string s1,string s2)
{
    if(s1.size() < s2.size())
        return strpl("0" + s1, s2);
    else if(s2.size() < s1.size())
        return strpl(s1, "0" + s2);

    string s3 = "";
    int tmp=0;
    string ans = "";
    int sz = s1.size();
    for(int i=sz-1;i>=0;i--)
    {
        tmp += (s1[i] - '0') + (s2[i] - '0');
        s3 += (tmp%10) + '0';
        tmp /= 10;
    }
    if(tmp > 0)
        s3 += (tmp%10) + '0';
    for(int i=s3.size()-1;i>=0;i--)
        ans += s3[i];
    cout << ans << "\n";
}
void strmi(string s1,string s2)
{
    if(s1.size() < s2.size())
        return strmi("0" + s1, s2);
    else if(s2.size() < s1.size())
        return strmi(s1, "0" + s2);

    string s3 = "";
    int tmp=0;
    string ans = "";
    int sz = s1.size();
    for(int i=sz-1;i>=0;i--)
    {
        tmp = (s1[i] - '0') - (s2[i] - '0');
        if(tmp < 0)
        {
            s1[i-1] --;
            tmp += 10;
        }
        s3 += (tmp + '0') ;
    }


    for(int i=s3.size()-1;i>=0;i--)
        ans += s3[i];
    cout << ans << "\n";
}
int main()
{
    int n;
    cin >> n;
    string s1,s2;
    for(int i=0;i<n;i++)
    {
        cin >> s1;
        cout << i+1 << "\n";
        if(s1[0] == '+')
        {
            cin >> s1 >> s2;
            strpl(s1,s2);
        }
        else if(s1[0] == '-')
        {
            cin >> s1 >> s2;
            strmi(s1,s2);
        }
        else
        {
            cin >> s2;
            strpl(s1,s2);
        }
    }
}
