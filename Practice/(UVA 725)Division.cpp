//https://vjudge.net/problem/35442/origin

#include <bits/stdc++.h>
using namespace std;

int test(int a,int b)
{
    int t[10];
    for(int i=0;i<10;i++)
        t[i]=0;
    for(int i=0;i<5;i++)
    {
        if(a==0)
            t[0]++;
        else
        {
            t[a%10]++;
            a/=10;
        }
        if(b==0)
            t[0]++;
        else
        {
            t[b%10]++;
            b/=10;
        }
    }
    for(int i=0;i<10;i++)
    {
        if(t[i]>1)
            return 0;
    }
    return 1;
}
int main()
{
    int n;
    int space=0;

    scanf("%d",&n);
    while( n > 0 )
    {
        int have_ans = 0;
        vector<int> ans;
        for(int i=1234 ; i<99999 ; i++)
        {
            have_ans = 0;
            if(i*n < 99999)
                have_ans = test(i*n,i);
            if(have_ans == 1)
                ans.push_back(i);
        }
        if(ans.size()!=0)
        {
            for(int i=0;i<ans.size();i++)
                printf("%05d / %05d = %d\n",ans[i]*n,ans[i],n);
        }
        else
        {
            printf("There are no solutions for %d.\n",n);
        }

        scanf("%d",&n);
        if(n != 0)
            printf("\n");
    }
    return 0;
}
