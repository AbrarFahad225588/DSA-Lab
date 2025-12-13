#include<bits/stdc++.h>
using namespace std;

int w[] = {1,5,8,9,10,17,17,20,24,30};     // price of each piece length
int dp[10005][10005];       // dp[i][j] = best for first i prices, rod length j

int rod_cut(int n, int l)
{
    for (int i = 1; i <= l; i++)   // i = piece index
    {
        for (int j = 1; j <= n; j++)  // j = rod length
        {
            if (i <= j)
                dp[i][j] = max(dp[i-1][j], w[i-1] + dp[i][j - i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[l][n];   // final answer
}

int main()
{
    memset(dp, 0, sizeof(dp));

    cout << rod_cut(9, 8) << endl;

    // print dp table
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
