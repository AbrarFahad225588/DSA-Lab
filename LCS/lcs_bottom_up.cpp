#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1="stones";
    string s2="longest";
    int n1s=s1.size(),n2s=s2.size();
    vector<vector<int>>dp(n2s+1,vector<int>(n1s+1,0));
    for(int i=1;i<=n2s;i++)
    {
        for(int j=1;j<=n1s;j++)
        {
           if(s2[i-1]==s1[j-1])
           {
             cout<<s2[i-1]<<" "<<s1[j-1]<<endl;
             dp[i][j]=1+dp[i-1][j-1];
           }else
           {
             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
        }
    }
    // for(int i=0;i<=n2s;i++)
    // {
    //     for(int j=0;j<=n1s;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
 
   int i = n2s, j = n1s;
    string ans = "";

    while(i > 0 && j > 0) {

        if(s2[i-1] == s1[j-1]) {  // character matched
            ans.push_back(s2[i-1]);
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    reverse(ans.begin(), ans.end());
    cout<<"LCS : "<< ans<<endl;

  cout<<dp[n2s][n1s];
}