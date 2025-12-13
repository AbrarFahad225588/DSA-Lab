#include <bits/stdc++.h>
using namespace std;

// Function to compute the LCS length and direction tables
void LCS_LENGTH(string X, string Y, vector<vector<int>> &c, vector<vector<char>> &b) {
    int m = X.size();
    int n = Y.size();
    
    c.assign(m + 1, vector<int>(n + 1, 0));
    b.assign(m + 1, vector<char>(n + 1, ' '));

    // Fill the tables in row-major order
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {  // characters match
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = '↖'; // ↖ (Diagonal)
            } 
            else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = '↑'; // ↑ (Up)
            } 
            else {
                c[i][j] = c[i][j - 1];
                b[i][j] = '←'; // ← (Left)
            }
        }
    }
}

// Function to print the LCS using the direction table
void PRINT_LCS(const vector<vector<char>> &b, const string &X, int i, int j) {
    if (i == 0 || j == 0)
        return;

    if (b[i][j] == '↖') { // ↖
        PRINT_LCS(b, X, i - 1, j - 1);
        cout << X[i - 1];
    } 
    else if (b[i][j] == '↑') // ↑
        PRINT_LCS(b, X, i - 1, j);
    else // ←
        PRINT_LCS(b, X, i, j - 1);
}

int main() {
    string X, Y;
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    int m = X.size(), n = Y.size();
    vector<vector<int>> c;
    vector<vector<char>> b;

    LCS_LENGTH(X, Y, c, b);

    cout << "\nLCS Table (lengths):\n";
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << setw(3) << c[i][j];
        }
        cout << "\n";
    }

    cout << "\nLongest Common Subsequence: ";
    PRINT_LCS(b, X, m, n);
    cout << "\n";
    
    cout << "Length of LCS = " << c[m][n] << endl;
    return 0;
}
