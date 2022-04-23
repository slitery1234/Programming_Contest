#include <bits/stdc++.h>
using namespace std;

bool func(int a,int b)
{
    int x=a,y=b;
    while(a/10!=0)
        a = (a/10)+(a%10);
    while(b/10!=0)
        b = (b/10)+(b%10);
    if(a == b)
        return x<y;
    return a<b;
}

int main()
{
    int n;
    cin >> n;
    string s;
    string ss[7];
    ss[0] = "College of Humanities";
    ss[1] = "College of Sciences";
    ss[2] = "College of Social Sciences";
    ss[3] = "College of Engineering";
    ss[4] = "College of Management";
    ss[5] = "College of Law";
    ss[6] = "College of Teacher Education";
    vector<int> ans[7];
    for(int i=0;i<n;i++)
    {
        cin >> s;
        ans[s[3]-'1'].push_back(atoi(s.c_str()));
    }

    for(int i=0;i<7;i++)
    {
        sort(ans[i].begin(),ans[i].end(),func);
    }
    for(int i=0;i<7;i++)
    {
        cout << ss[i] << "\n";
        for(int j=0;j<ans[i].size();j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }


}
