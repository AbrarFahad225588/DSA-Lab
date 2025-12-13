#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int lcs(string a,string b,int m,int n)
{
   if(m==0 || n==0) return 0;
   if(dp[m-1][n-1]!=-1) return dp[m-1][n-1];
   if(a[m-1]==b[n-1]) 
   return dp[m-1][n-1]=1+lcs(a,b,m-1,n-1);
   else
   return dp[m-1][n-1]=max(lcs(a,b,m-1,n),lcs(a,b,m,n-1));
}
int main()
{
    string a="acb",b="abc";
    memset(dp,-1,sizeof(dp));
    cout<<lcs(a,b,3,3);
}