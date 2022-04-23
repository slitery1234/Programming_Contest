#include <bits/stdc++.h>
using namespace std;

int x[8];
set<int> used_num;
vector<int> edge[10];
vector<char> used_char;
map<char,int> cons_ctoi;
map<int,char> cons_itoc;
int ans[8];
int bw;
int n;

int dfs(int index)
{
    if(index == 8)
    {
        int cnt = 0;
        for(int i=1;i<=8;i++)
        {
            int p1,p2;
            for(int j=0;j<edge[i].size();j++)
            {
                for(int k=0;k<8;k++)
                {
                    if(x[k] == i)
                        p1 = k;
                    if(x[k] == edge[i][j])
                        p2 = k;
                }
                if(abs(p1-p2) > cnt)
                    cnt = abs(p1-p2);
            }
        }
        if(cnt < bw)
        {
            bw = cnt;
            for(int i=0;i<8;i++)
                ans[i]=x[i];
        }
        return 1;
    }
    else
    {
        for(int i=1; i<=8; i++)
        {
            if(used_num.count(i) == 0)
            {
                x[index] = i;
                used_num.insert(i);
                dfs(index+1);
                used_num.erase(used_num.find(i));
            }
        }
        return 0;
    }
}

int main()
{
    char s[2000];
    scanf("%s",s);
    while(s[0] != '#')
    {
        bw = 0x3f3f3f3f;
        int poi1,poi2,md = 0,n=1;
        set<char> se;
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
            {
                if(se.count(s[i])==0)
                {
                    se.insert(s[i]);
                    used_char.push_back(s[i]);
                }
            }
        }
        sort(used_char.begin(),used_char.end());
        n=used_char.size();
        for(int i=0;i<n;i++)
        {
            cons_ctoi.insert(make_pair(used_char[i],i+1));
            cons_itoc.insert(make_pair(i+1,used_char[i]));
        }

        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i] == ':')
            {
                poi1 = cons_ctoi[s[i-1]];
                md = 1;
            }
            else if(s[i] == ';')
                md = 0;
            else if(md == 1)
            {
                poi2 = cons_ctoi[s[i]];
                edge[poi1].push_back(poi2);
                edge[poi2].push_back(poi1);
            }
        }

        dfs(0);
        for(int i=0;i<n;i++)
            printf("%c ",cons_itoc[ans[i]]);
        printf("-> %d\n",bw);

        used_num.clear();
        used_char.clear();
        cons_ctoi.clear();
        cons_itoc.clear();
        for(int i=0;i<10;i++)
            edge[i].clear();
        scanf("%s",s);
    }
    return 0;
}
