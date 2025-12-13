#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;
using ll = unsigned int;

ll calcRow(std::vector<std::vector<ll>>& mat, ll row, ll cols) {
    ll v = 0;

    for (ll i = 0; i < cols; i++) {
        v ^= mat[row][i];
    }

    return v;
}

ll calcCol(std::vector<std::vector<ll>>& mat, ll col, ll rows) {
    ll v = 0;

    for (ll i = 0; i < rows; i++) {
        v ^= mat[i][col];
    }

    return v;
}

ll calSum(std::vector<std::vector<ll>>& mat, ll rows, ll cols) {
    ll sum = 0;
    for (ll i = 0; i < rows; i++) {
        sum += calcRow(mat, i, cols);
    }
    for (ll i = 0; i < cols; i++) {
        sum += calcCol(mat, i, rows);
    }
    return sum;
}

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll rows, cols;
        cin >> rows >> cols;

        std::vector<std::vector<ll>> mat (rows, std::vector<ll>(cols));

        for (ll i = 0; i < rows ; i++) {
            for (ll j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }

        ll prevsum = calSum(mat, rows, cols);

        ll rIdx = 0, cIdx = 0;

        // get max row
        ll _max = INT_MIN;
        for (ll i = 0; i < rows; i++) {
            ll val = calcRow(mat, i, cols);

            if (val > _max) {
                _max = val;
                rIdx = i;
            }
        }

        // get max col
        _max = 0;
        for (ll i = 0; i < cols; i++) {
            ll val = calcCol(mat, i, rows);

            if (val > _max) {
                _max = val;
                cIdx = i;
            }
        }

        // cout << rIdx << " " << cIdx << endl;
        mat[rIdx][cIdx] = 0;
/*
        ll colReplace = calcCol(mat, cIdx, rows);
        ll rowReplace = calcRow(mat, rIdx, cols);

        mat[rIdx][cIdx] = colReplace;
        ll colSum = calSum(mat, rows, cols);

        mat[rIdx][cIdx] = rowReplace;
        ll rowSum = calSum(mat, rows, cols);
*/
        ll v1 = calcCol(mat, cIdx, rows);
        ll v2 = calcRow(mat, rIdx, cols);

        mat[rIdx][cIdx] = (v1 > v2) ? v1 : v2;
ll sum = calSum(mat, rows, cols);
        cout << min(sum, prevsum) << endl;
    }
}
