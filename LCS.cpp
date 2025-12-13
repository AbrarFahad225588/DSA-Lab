#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s, t;
  cin >> s >> t;
  int n = s.length();
  int m = t.length();
  int dp[n + 1][m + 1];
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < m; j++)
    {
      if (s[i - 1] == t[i - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  int i = n, j = m;
  string lcs = "";
  while (i > 0 && j > 0)
  {
    if (s[i - 1] == t[j - 1])
    {
      lcs += s[i - 1];
      i--;
      j--;
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
    {
      i--;
    }
    else
    {
      j--;
    }
  }
  cout<<lcs<<endl;
  reverse(lcs.begin(),lcs.end());
  cout<<lcs<<endl;
}