#include<bits/stdc++.h>
using namespace std;
int dp[100];
int rodcut(int w[],int n)
{
    if(n<=0) return 0;
    if(dp[n]!=-1) return dp[n];
    int q=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        q=max(q,w[i-1]+rodcut(w,n-i));
    }
    return dp[n]=q;
}
int main()
{
    int w[]={4,5,6};
    memset(dp,-1,sizeof(dp));
    cout<<rodcut(w,3);
}