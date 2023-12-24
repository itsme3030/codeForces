#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
    int n; cin >> n;
    vector<int> b(n);
    vector<int> p(n);
    for (auto &x : b) cin >> x;
    for (auto &x : p) cin >> x;

    int root = -1;
    for (int i = 0; i < n; i++) {
        if (b[i] == i + 1) {
            root = i + 1;
            break;
        }
    }

    if (p[0] != root) {
        cout << -1 << "\n";
        return;
    }

    set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(p[i]);
        if (st.find(b[p[i] - 1]) == st.end()) {
            cout << -1 << "\n";
            return;
        }
    }

    vector<int> dp(n + 1);

    dp[root] = 0;
    int val[n + 1]; val[root] = 0;
    for (int i = 1; i < n; i++) {
        dp[p[i]] = dp[b[p[i] - 1]] + 1;
        if (dp[p[i]] <= dp[p[i-1]]) {
            dp[p[i]] = dp[p[i-1]] + 1;
        }
        val[p[i]] = dp[p[i]] - dp[b[p[i] - 1]];
    }

    for (int i = 1; i <= n; i++) cout << val[i] << " "; cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}