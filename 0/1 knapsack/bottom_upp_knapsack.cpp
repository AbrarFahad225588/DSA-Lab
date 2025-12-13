#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> wt = {1,2,3};
    vector<int> val = {6,5,7};
    int cap = 5;
    int n = wt.size();

    vector<vector<int>> dp(n+1, vector<int>(cap+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= cap; c++) {

            // Without taking item i-1
            int notTake = dp[i-1][c];
            int take = 0;

            // If we can take it
            if (c >= wt[i-1])
                take = val[i-1] + dp[i-1][c - wt[i-1]];

            dp[i][c] = max(take, notTake);
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=cap;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    cout << dp[n][cap];  // final answer = 150
}
