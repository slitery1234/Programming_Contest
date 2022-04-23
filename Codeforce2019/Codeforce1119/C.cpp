#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt[n+1];
    for(int i=0; i<=n; i++)
        cnt[i] = 0;
    int a[3][n-2];
    int midline=-1;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<n-2; j++)
        {
            cin >> a[i][j];
            cnt[a[i][j]]++;
        }

    }

    for(int i=0; i<3; i++)
    {
        int j;
        for(j=1; j<n-2; j++)
        {
            if(cnt[a[i][j]] <= 1)
                break;
        }
        if(j == n-2)
            midline = i;
    }
    if(midline == 0)
    {
        for(int i=0; i<n-2; i++)
        {
            if(cnt[ a[1][i] ] == 1)
            {
                cout << a[1][i] << " ";
                break;
            }
        }
        for(int i=0; i<n-2; i++)
        {
            if(cnt[ a[1][i] ] == 2)
            {
                cout << a[1][i] << " ";
                break;
            }
        }
        for(int i=0; i<n-2; i++)
        {
            if(cnt[ a[0][i] ] == 3)
                cout << a[0][i] << " ";
        }

        for(int i=0; i<n-2; i++)
        {
            if(cnt[ a[2][i] ] == 2)
            {
                cout << a[2][i] << " ";
                break;
            }
        }
        for(int i=0; i<n-2; i++)
        {
            if(cnt[ a[2][i] ] == 1)
            {
                cout << a[2][i] << " ";
                break;
            }
        }
    }
    else if(midline == 1)
    {
        for(int i=0; i<n-2; i++)
        {
            if(cnt[ a[0][i] ] == 1)
            {
                cout << a[0][i] << " ";
                break;
            }
        }
        for(int i=0; i<n-2; i++)
        {
            if(cnt[ a[0][i] ] == 2)
            {
                cout << a[0][i] << " ";
                break;
            }
        }
        for(int i=0; i<n-2; i++)
        {
            if(cnt[ a[1][i] ] == 3)
                cout << a[1][i] << " ";
        }

        for(int i=0; i<n-2; i++)
        {
            if(cnt[ a[2][i] ] == 2)
            {
                cout << a[2][i] << " ";
                break;
            }
        }
        for(int i=0; i<n-2; i++)
        {
            if(cnt[ a[2][i] ] == 1)
            {
                cout << a[2][i] << " ";
                break;
            }
        }
    }
    else if(midline == 2)
    {
        for(int i=0; i<n-2; i++)
        {
            if(cnt[ a[1][i] ] == 1)
            {
                cout << a[1][i] << " ";
                break;
            }
        }
        for(int i=0; i<n-2; i++)
        {
            if(cnt[ a[1][i] ] == 2)
            {
                cout << a[1][i] << " ";
                break;
            }
        }
        for(int i=0; i<n-2; i++)
        {
            if(cnt[ a[2][i] ] == 3)
                cout << a[2][i] << " ";
        }

        for(int i=0; i<n-2; i++)
        {
            if(cnt[ a[0][i] ] == 2)
            {
                cout << a[0][i] << " ";
                break;
            }
        }
        for(int i=0; i<n-2; i++)
        {
            if(cnt[ a[0][i] ] == 1)
            {
                cout << a[0][i] << " ";
                break;
            }
        }
    }
    return 0;
}
