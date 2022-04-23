#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[200];
    fgets(s,200,stdin);
    char *token=NULL;
    token=strtok(s," .");
    cout << token << endl;
    while(token!=NULL)
    {
        token=strtok(NULL," .");
        cout << token << endl;
    }

}
