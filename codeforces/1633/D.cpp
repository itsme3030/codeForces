#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
void solve();
int d[1001];
    
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (auto &x : d) x = 1e18;
    d[1] = 0;
    
    for (int i = 1; i <= 1000; i++) {
        for (int x = 1; x <= i; x++) {
            int j = i + i/x;
            if (j <= 1000) d[j] = min(d[j], d[i] + 1);
        }
    }

    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    int n,k; cin >> n >> k;
    vector<int> b(n), c(n);
    for (auto &x : b) cin >> x;
    for (auto &x : c) cin >> x;
    int mx = d[1000];
    k = min(k, mx*n);
    int dp[k+1];
    for (auto &x : dp) x = 0;
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 0; j--) {
            if (j > 0) dp[j] = max(dp[j-1], dp[j]);
            if (j >= d[b[i]]) {
                dp[j] = max(dp[j-d[b[i]]] + c[i], dp[j]);
            }
        }
    }
    cout << dp[k] << "\n";
}
