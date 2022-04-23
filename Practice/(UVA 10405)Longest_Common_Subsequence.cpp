//https://vjudge.net/problem/19201/origin

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    while(getline(cin,s1))
    {
        getline(cin,s2);
        int lcs[s1.size()+1][s2.size()+1];

        for(int i=0;i<=s1.size();i++)
        {
            for(int j=0;j<=s2.size();j++)
            {
                lcs[i][j]=0;
            }
        }

        for(int i=1;i<=s1.size();i++)
        {
            for(int j=1;j<=s2.size();j++)
            {
                if(s1[i-1] == s2[j-1])
                    lcs[i][j] = lcs[i-1][j-1] +1;
                else
                    lcs[i][j] = max(lcs[i][j-1],lcs[i-1][j]);
            }
        }
        cout << lcs[s1.size()][s2.size()] << "\n";
    }
    return 0;
}
