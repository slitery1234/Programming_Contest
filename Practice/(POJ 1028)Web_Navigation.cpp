//http://poj.org/problem?id=1028

#include <iostream>
#include <stack>
#include <string>
using namespace std;



int main()
{
    stack<string> bk,fw;
    string cmd;
    string url;
    string initial_page = "http://www.acm.org/";

    while( cin >> cmd )
    {

        if(cmd == "VISIT")
        {
            cin >> url;
            if(bk.size() == 0)
                bk.push(initial_page);
            bk.push(url);
            cout << bk.top() << "\n";
            while(fw.size() != 0)
                fw.pop();
        }
        else if(cmd == "BACK")
        {
            if(bk.size() > 1)
            {
                fw.push(bk.top());
                bk.pop();
                cout << bk.top() << "\n";
            }
            else
            {
                cout << "Ignored\n";
            }
        }
        else if(cmd == "FORWARD")
        {
            if(bk.size() == 0)
                bk.push(initial_page);

            if(fw.size() != 0)
            {
                cout << fw.top() << "\n";
                bk.push(fw.top());
                fw.pop();
            }
            else
                cout << "Ignored\n";
        }
        else if(cmd == "QUIT")
        {
            break;
        }
    }


    return 0;
}
