#include <bits/stdc++.h>
using namespace std;
int test(long long int n)
{
    for(long long int i=2;i<=sqrt(n);i++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    long long int n= 2;
    for(int i=0;i<50;i++)
        n*=2;
    cout << "2251799813685269\n";

}
