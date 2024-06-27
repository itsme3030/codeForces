#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    vector<vector<int>> left_cross(n, vector<int> (n, 0));
    //left cross
    for(int col = 0; col < n; col++) {
        int tcol = col;
        int row = 0;
        while (row < n-col) {
            left_cross[row][tcol] += v[row][tcol];
            if (row-1 >= 0 && tcol - 1 >= 0) left_cross[row][tcol] += left_cross[row-1][tcol-1];
            row++, tcol++;
        }
    }

    for(int row = n-1; row >= 0; row--) {
        int trow = row-1;
        int col = n-2;
        int val = left_cross[row][n-1];
        while (col >= n-1-row) {
            left_cross[trow][col] = val;
            col--, trow--;
        }
    }


    for(int row = 1; row < n; row++) {
        int trow = row;
        int col = 0;
        while (col < n-row) {
            left_cross[trow][col] += v[trow][col];
            if(trow - 1 >= 0 && col - 1 >= 0) left_cross[trow][col] += left_cross[trow-1][col-1];
            trow++, col++;
        }
    }

    for(int col = 0; col < n-1; col++) {
        int tcol = col-1;
        int row = n-2;
        int val = left_cross[n-1][col];
        while (row >= n-1-col) {
            left_cross[row][tcol] = val;
            row--, tcol--;
        }
    }



    vector<vector<int>> right_cross(n, vector<int> (n, 0));
    //right cross

    for(int col = 0; col < n; col++) {
        int tcol = col;
        int row = 0;

        while (row <= col) {
            right_cross[row][tcol] += v[row][tcol];
            if (row - 1 >= 0 && tcol+1 < n) right_cross[row][tcol] += right_cross[row-1][tcol+1];
            tcol--, row++;
        }
    }

    for(int row = 0; row < n; row++) {
        int trow = row-1;
        int col = 1;
        int val = right_cross[row][0];
        while (col <= row) {
            right_cross[trow][col] = val;
            col++, trow--;
        }
    }


    for(int row = 1; row < n; row++) {
        int trow = row;
        int col = n-1;
        while (col >= row) {
            right_cross[trow][col] += v[trow][col];
            if (trow - 1 >= 0 && col + 1 < n) right_cross[trow][col] += right_cross[trow-1][col+1];
            col--, trow++;
        }
    }

    for(int col = 1; col < n; col++) {
        int tcol = col+1;
        int row = n-2;
        int val = right_cross[n-1][col];
        while (row >= col) {
            right_cross[row][tcol] = val;
            row--, tcol++;
        }
    }


    //find big-2 for both bishop
    int ans = 0;
    int mxo = 0, mxe = 0;
    int mxoi = 0, mxoj = 0, mxei = 0, mxej = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if ((i+j) % 2) {
                if (left_cross[i][j] + right_cross[i][j] - v[i][j] >= mxo) {
                    mxo = left_cross[i][j] + right_cross[i][j] - v[i][j];
                    mxoi = i, mxoj = j;
                }
            } else {
                if (left_cross[i][j] + right_cross[i][j] - v[i][j] >= mxe) {
                    mxe = left_cross[i][j] + right_cross[i][j] - v[i][j];
                    mxei = i, mxej = j;
                }
            }
        }
    }
    ans += mxo;
    ans += mxe;
    cout << ans << "\n";
    cout << mxoi + 1 << " " << mxoj + 1 << " " << mxei + 1 << " " << mxej + 1 << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}