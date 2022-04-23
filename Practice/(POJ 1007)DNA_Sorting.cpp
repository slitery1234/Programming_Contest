//http://poj.org/problem?id=1007

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string s1,string s2)
{
    int a=0,b=0;
    char temp;
    for(int i=0;i<s1.size();i++)
    {
        for(int j=i;j<s1.size();j++)
        {
            if(s1[i] > s1[j])
            {
                a++;
            }
            if(s2[i] > s2[j])
            {
                b++;
            }
        }
    }
    return a<b;
}


int main()
{
    int n,m;
    cin >> n >> m;
    string s[m];
    for(int i=0;i<m;i++)
        cin >> s[i];

    sort(s,s+m,cmp);

    for(int i=0;i<m;i++)
        cout << s[i] << "\n";
    return 0;
}
