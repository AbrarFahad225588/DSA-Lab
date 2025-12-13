#include<bits/stdc++.h>
using namespace std;
int dp[10005][10005];//dp[n][cap]
int knapsack(vector<int>&wt,vector<int>&val,int cap,int n)
{
   
    if(cap==0 || n<0 ) return 0; 
    if(dp[n][cap]!=-1) return dp[n][cap];
    int notTake=knapsack(wt,val,cap,n-1);;
    int take=0;
    if(cap>=wt[n])
    take =val[n]+knapsack(wt,val,cap-wt[n],n-1);
    return dp[n][cap]=max(take,notTake);
}

int main()
{
    vector<int>wt={10,8,30};
    vector<int>val={10,50,100};
    int cap=40;
    int n=4;
    memset(dp,-1,sizeof(dp));
    cout<<knapsack(wt,val,cap,n-1);

}