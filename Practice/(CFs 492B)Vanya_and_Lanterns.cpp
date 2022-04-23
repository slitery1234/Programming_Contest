//https://vjudge.net/problem/89213/origin

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,str;
    scanf("%d%d",&n,&str);
    int input;
    set<int> s;
    vector<int> lant;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&input);
        s.insert(input);
    }
    for(auto x:s)
        lant.push_back(x);
    double ans = 0;
    sort(lant.begin(),lant.end());

    for(int i=1; i<lant.size(); i++)
    {
        if(ans < ((double)(lant[i] - lant[i-1]) / 2))
            ans = (double)(lant[i] - lant[i-1]) / 2;
    }

    if(s.count(0) && s.count(str))
    {

    }
    else if(s.count(0))
    {
        if(ans < (str - lant.back()) )
            ans = str - lant.back();
    }
    else if(s.count(str))
    {
        if(ans < lant[0])
            ans = lant[0];
    }
    else
    {
        if(ans < lant[0])
            ans = lant[0];
        if(ans < (str - lant.back()) )
            ans = str - lant.back();
    }

    printf("%.10f",ans);
    return 0;
}
