#include <bits/stdc++.h>
#define lint long long int
using namespace std;

// 求 ax + by = d 的因數 的一組 (x,y)
// 若 a,b 互質 則有 ax = 1 mod b
void ExGCD(lint a,lint b,lint &d,lint &x,lint &y)
{
    if(b == 0){
        x = 1;
        y = 0;
        d = a;
        return;
    }
    ExGCD(b, a%b, d, y, x);
    y = y - (a/b*x);
    return;
}

int main()
{
    lint a=21,b=36;
    lint x=0, y=0;
    lint d=9;
    ExGCD(a,b,d,x,y);
    cout << x << " " << y << "\n";
    cout << a << "*" << x << "+" << b << "*" << y << "=" << d;
}
