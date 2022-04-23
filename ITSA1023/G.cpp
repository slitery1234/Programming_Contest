#include <bits/stdc++.h>
using namespace std;

int a[8][8];

int judge(int i,int j)
{
    if(i > 1)
    {
        if(a[i-1][j] == 2)
        {
            for(int ii=i-1;ii>=0;ii--)
            {
                if(a[ii][j] == 2)
                    continue;
                else if(a[ii][j] == 1)
                    return 1;
                else if(a[ii][j] == 0)
                    break;
            }
        }
    }
    if(i < 6)
    {
        if(a[i+1][j] == 2)
        {
            for(int ii=i+1;ii<8;ii++)
            {
                if(a[ii][j] == 2)
                    continue;
                else if(a[ii][j] == 1)
                    return 1;
                else if(a[ii][j] == 0)
                    break;
            }
        }
    }
    if(j > 1)
    {
        if(a[i][j-1] == 2)
        {
            for(int jj=j-1;jj>=0;jj--)
            {
                if(a[i][jj] == 2)
                    continue;
                else if(a[i][jj] == 1)
                    return 1;
                else if(a[i][jj] == 0)
                    break;
            }
        }
    }
    if(j < 6)
    {
        if(a[i][j+1] == 2)
        {
            for(int jj=j+1;jj<8;jj++)
            {
                if(a[i][jj] == 2)
                    continue;
                else if(a[i][jj] == 1)
                    return 1;
                else if(a[i][jj] == 0)
                    break;
            }
        }
    }
    if(i > 1 && j > 1)
    {
        if(a[i-1][j-1] == 2)
        {
            for(int ii=i-1,jj=j-1; ii>=0&&jj>=0 ;ii--,jj--)
            {
                if(a[ii][jj] == 2)
                    continue;
                else if(a[ii][jj] == 1)
                    return 1;
                else if(a[ii][jj] == 0)
                    break;
            }
        }
    }
    if(i < 6 && j < 6)
    {
        if(a[i+1][j+1] == 2)
        {

            for( int ii=i+1,jj=j+1;ii<8&&jj<8 ;ii++,jj++)
            {
                if(a[ii][jj] == 2)
                    continue;
                else if(a[ii][jj] == 1)
                    return 1;
                else if(a[ii][jj] == 0)
                    break;
            }
        }
    }
    if(i > 1 && j < 6)
    {
        if(a[i-1][j+1] == 2)
        {
            for(int ii=i-1,jj=j+1; ii>=0&&jj<8 ;ii--,jj++)
            {
                if(a[ii][jj] == 2)
                    continue;
                else if(a[ii][jj] == 1)
                    return 1;
                else if(a[ii][jj] == 0)
                    break;
            }
        }
    }
    if(i < 6 && j > 1)
    {
        if(a[i+1][j-1] == 2)
        {
            for(int ii=i+1,jj=j-1; ii<8&&jj>=0 ;ii++,jj--)
            {
                if(a[ii][jj] == 2)
                    continue;
                else if(a[ii][jj] == 1)
                    return 1;
                else if(a[ii][jj] == 0)
                    break;
            }
        }
    }
    return 0;
}

int main()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
            cin >> a[i][j];
    }

    int ans=0;

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(a[i][j] == 0)
            {
                ans += judge(i,j);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}


