//https://vjudge.net/problem/21415/origin

#include <bits/stdc++.h>
using namespace std;

int input[6];

int push_six()
{
    return input[5];
}
int push_five()
{
    input[0] -= input[4] * 11;
    return input[4];
}
int push_four()
{
    input[1] -= input[3] * 5;
    return input[3];
}
int push_three()
{
    int x = 4 - (input[2] % 4);
    if(x == 4)
        return input[2]/4;
    else
    {
        input[1] -= (x*2-1);
        input[0] -= (x+4);
        return input[2]/4 +1;
    }
}
int push_two()
{
    if(input[1] > 0)
    {
        if(input[1]%9 == 0)
            return input[1]/9;
        else
        {
            int x = 9 - input[1]%9;
            input[0] -= x*4;
            return input[1]/9 + 1;
        }
    }
    else
    {
        int x = 0 - input[1];
        input[0] -= x*4;
        return 0;
    }
}
int push_one()
{
    if(input[0] > 0)
    {
        if(input[0]%36 == 0)
            return input[0]/36;
        else
            return input[0]/36 +1;
    }
    else
        return 0;
}

int main()
{
    while( true )
    {
        int break_test = 0;
        int ans = 0;

        for(int i=0; i<6; i++)
        {
            cin >> input[i];
            break_test += input[i];
        }
        if(break_test == 0)
            break;

        ans+=push_six();
        ans+=push_five();
        ans+=push_four();
        ans+=push_three();
        ans+=push_two();
        ans+=push_one();
        cout << ans << "\n";

    }
    return 0;
}
/*
0 = can't use
1 = empty

6x6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

5x5 + 1x1 * 11
1 1 1 1 1 1
0 0 0 0 0 1
0 0 0 0 0 1
0 0 0 0 0 1
0 0 0 0 0 1
0 0 0 0 0 1

4x4 + 2x2 * 5
2x2 = 1x1 * 4
1 1 1 1 1 1
1 1 1 1 1 1
0 0 0 0 1 1
0 0 0 0 1 1
0 0 0 0 1 1
0 0 0 0 1 1

3x3 * 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

3x3 * 3
+2x2 * 1 + 1x1 * 5
0 0 0 1 1 1
0 0 0 1 1 1
0 0 0 1 1 1
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
3x3 * 2
+2x2 * 3 + 1x1 * 6
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
3x3 * 1
+2x2 * 5 + 1x1 *7
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
0 0 0 1 1 1
0 0 0 1 1 1
0 0 0 1 1 1

3x3 = 2x2 + 1x1*5
1 1 1
0 0 1
0 0 1
*/
