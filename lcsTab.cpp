#include<bits/stdc++.h>
using namespace std;
int main()
{
    string x,y;
    cin>>x>>y;
    int m=x.size(),n=y.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++){
            if(!i||!j) dp[i][j]=0;
            else if(x[i-1]==y[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        cout<<dp[m][n]<<endl;
}