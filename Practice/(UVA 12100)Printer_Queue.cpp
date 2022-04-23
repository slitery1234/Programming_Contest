//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3252

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n_c;
    cin >> n_c;
    for(int n_i=0;n_i<n_c;n_i++)
    {
        int a,b,input;
        int minute = 0;
        cin >> a >> b;
        queue< pair<int,int> > q;
        priority_queue<int> pr;

        for(int i=0;i<a;i++)
        {
            cin >> input;
            q.push( {i,input} );
            pr.push(input);
            //cout << i << input << "\n";
        }

        while ( !( (q.front().first == b) && (q.front().second == pr.top()) ) )
        {
            if(q.front().second != pr.top())
            {
                q.push(q.front());
                q.pop();
            }
            else
            {
                pr.pop();
                q.pop();
                minute++;
            }
        }

        minute++;
        cout << minute << "\n";

    }
}
