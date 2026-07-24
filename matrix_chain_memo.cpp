#include<bits/stdc++.h>
using namespace std;
int mcmMemo(int p[],int i,int j,int memo[][1000])
{
    if(i==j ) return 0;
    if(memo[i][j]!=-1) return memo[i][j];
    int m=INT_MAX;
    for(int k=i;k<j;k++)
    {
        m=min(m,mcmMemo(p,i,k,memo)+mcmMemo(p,k+1,j,memo)+p[i-1]*p[j]*p[k]);
    }
    return memo[i][j]=m;
}
int main()
{
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    int p[100];

    cout << "Enter dimensions array (size " << n + 1 << "): ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    int dp[100][1000];

    // Initialize DP array with -1
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            dp[i][j] = -1;
        }
    }

    int result = mcmMemo(p, 1, n, dp);

    cout << "Minimum multiplication cost: " << result << endl;

    return 0;
}