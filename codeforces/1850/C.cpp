#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
    vector<vector<char>> v(8, vector<char> (8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> v[i][j];
        }
    }

    string s = "";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (v[j][i] != '.') {
                s += v[j][i];
            }
        }
    }
    cout << s << "\n";

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}