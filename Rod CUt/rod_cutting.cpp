#include<bits/stdc++.h>
using namespace std;
int w[]={4,5,6} ;
int dp[100005];

int  rod_cut(int n)
{  
   
   if(n==0) return 0;
   if(dp[n]!=-1) return dp[n];
   int q=INT_MIN;
   int len = sizeof(w) / sizeof(w[0]);

    for (int i = 1; i <= min(n, len); i++) {
        q = max(q, w[i-1] + rod_cut(n - i));
    }
   return dp[n]=q;
}
int main()
{   
    memset(dp,-1,sizeof(dp));
    cout<<rod_cut(3)<<endl;
   
}