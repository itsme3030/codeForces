#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    int n,q; cin >> n >> q;
    string s; cin >> s;
    int dp[n][6];
    vector<vector<char>> pos(6, vector<char> (3));
    pos[0] = {'a', 'b', 'c'};
    pos[1] = {'b', 'c', 'a'};
    pos[2] = {'c', 'a', 'b'};
    pos[3] = {'a', 'c', 'b'};
    pos[4] = {'b', 'a', 'c'};
    pos[5] = {'c', 'b', 'a'};

    for (int j = 0; j < 6; j++) {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != pos[j][i % 3]) {
                cur+=1;
            }
            dp[i][j] = cur;
        }
    }

    while (q--) {
        int l,r; cin >> l >> r;
        r--, l--;
        int ans = INT_MAX;
        for (int j = 0; j < 6; j++) {
            int curr = dp[r][j];
            if (l > 0) curr -= dp[l-1][j];
            ans = min(ans, curr);
        }
        cout << ans << "\n";
    }
}
