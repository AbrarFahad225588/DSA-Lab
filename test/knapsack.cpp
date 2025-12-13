#include<bits/stdc++.h>
using namespace std;
int dp[10005][10005];
int knapsack(int v[],int w[],int c,int n)
{
    if(n==0 || c==0 ) return 0;
    if(dp[n-1][c]!=-1) return dp[n-1][c];
    int notake=knapsack(v,w,c,n-1);
    int take=INT_MIN;
    if(c>=w[n-1])
    {
        take=v[n-1]+knapsack(v,w,c-w[n-1],n-1);
    }
    return dp[n-1][c]=max(take,notake);

}
int main()
{
    int v[]={1,2,3};
    int w[]={2,3,4};
    memset(dp,-1,sizeof(dp));
    cout<<knapsack(v,w,5,3);
}