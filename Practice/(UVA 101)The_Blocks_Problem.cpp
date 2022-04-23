//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=37

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v[n];
    string cmd;
    int a,b;
    for(int i=0; i<n; i++)
        v[i].push_back(i);

    while(cin >> cmd)
    {
        if(cmd == "move")
        {
            cin >> a >> cmd >> b;
            int ai,aj,bi,bj;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<v[i].size(); j++)
                {
                    if(v[i][j] == a)
                    {
                        ai = i;
                        aj = j;
                    }
                    if(v[i][j] == b)
                    {
                        bi = i;
                        bj = j;
                    }
                }
            }

            if(ai == bi)
                continue;

            if(cmd == "onto")
            {
                for(int j=aj+1;j<v[ai].size();j++)
                    v[v[ai][j]].push_back(v[ai][j]);

                for(int j=bj+1;j<v[bi].size();j++)
                    v[v[bi][j]].push_back(v[bi][j]);

                v[ai].resize(aj);
                v[bi].resize(bj+1);

                v[bi].push_back(a);
            }
            else if(cmd == "over")
            {
                for(int j=aj+1;j<v[ai].size();j++)
                    v[v[ai][j]].push_back(v[ai][j]);

                v[ai].resize(aj);
                v[bi].push_back(a);
            }
        }
        else if(cmd == "pile")
        {
            cin >> a >> cmd >> b;
            int ai,aj,bi,bj;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<v[i].size(); j++)
                {
                    if(v[i][j] == a)
                    {
                        ai = i;
                        aj = j;
                    }
                    if(v[i][j] == b)
                    {
                        bi = i;
                        bj = j;
                    }
                }
            }

            if(ai == bi)
                continue;

            if(cmd == "onto")
            {
                for(int j=bj+1;j<v[bi].size();j++)
                    v[v[bi][j]].push_back(v[bi][j]);

                v[bi].resize(bj+1);
                for(int j=aj;j<v[ai].size();j++)
                    v[bi].push_back(v[ai][j]);
                v[ai].resize(aj);
            }
            else if(cmd == "over")
            {
                for(int j=aj;j<v[ai].size();j++)
                    v[bi].push_back(v[ai][j]);
                v[ai].resize(aj);
            }
        }
        else if(cmd == "quit")
        {
            for(int i=0; i<n; i++)
            {
                cout << i << ":";
                for(int j=0; j<v[i].size(); j++)
                    cout << " " << v[i][j];
                cout << "\n";
            }
            break;
        }
    }

    return 0;
}
