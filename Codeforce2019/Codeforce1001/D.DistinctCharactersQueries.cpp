#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[100040];
    scanf("%s",s);
    vector<set<int>> v;
    v.resize(26*sizeof(set<int>));

    for(int i=0;i<100040;i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            v[s[i]-'a'].insert(i);
        else if(s[i] == '\0')
            break;
    }


    int n;
    scanf("%d",&n);
    for(int ni=0;ni<n;ni++)
    {
        int com;
        scanf("%d",&com);
        if(com == 1)
        {
            int pos;
            char c;
            scanf("%d %c",&pos,&c);
            pos--;
            v[s[pos]-'a'].erase(pos);
            s[pos] = c;
            v[c-'a'].insert(pos);
        }
        else if(com == 2)
        {
            int l,r;
            scanf("%d %d",&l,&r);
            l--;
            r--;
            int ans = 0;
            for(int i=0;i<26;i++)
            {
                set<int>::iterator low;
                low = v[i].lower_bound(l);
                if(low!=v[i].end() && *low<=r)
                    ans++;
            }
            printf("%d\n",ans);
        }
    }

    return 0;
}
