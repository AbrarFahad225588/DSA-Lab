#include<bits/stdc++.h>
using namespace std;
int lcs(string &s1,string &s2,int m,int n, vector<vector<int>>&memo)
{
   if(m==0 || n==0 ) return 0;
   if(memo[m][n]!=-1) return memo[m][n];
   if(s1[m-1]==s2[n-1])
   {
     return memo[m][n]=1+lcs(s1,s2,m-1,n-1,memo);
   }else
   {
     return memo[m][n]=max(lcs(s1,s2,m-1,n,memo),lcs(s1,s2,m,n-1,memo));
   }
}
string reconstructLCS(string &s1, string &s2, vector<vector<int>>& memo)
{
    int i = s1.size();
    int j = s2.size();

    string ans = "";

    while(i > 0 && j > 0)
    {
        if(s1[i-1] == s2[j-1]) {
            ans.push_back(s1[i-1]);
            i--; j--;
        }
        else if(memo[i-1][j] >= memo[i][j-1])
            i--;
        else
            j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string s1="stones";
    string s2="longest";
    int m=s1.size(),n=s2.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    cout<<"LCS Length : "<<lcs(s1,s2,m,n,dp)<<endl;
    cout<<"LCS word : "<<reconstructLCS(s1,s2,dp)<<endl;

}