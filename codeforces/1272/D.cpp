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
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    // vector<vector<int>> dp(n, vector<int>(2, 0));
    // dp[0][0] = 0;
    // dp[0][1] = 1;
    // int mx = 1;
    // for(int i = 1; i < n; i++) {

    //     dp[i][0] = dp[i-1][1];
    //     dp[i][1] = max(dp[i][1], dp[i-1][1] + (v[i] > v[i-1]));
    //     // if (i > 1) {
    //     //     dp[i][1] = max(dp[i][1], dp[i-1][0] + (v[i] > v[i-2]));
    //     // }
    //     mx = max(mx, dp[i][0]);
    //     mx = max(mx, dp[i][1]);
    // }
    // // cout << max(dp[])
    // cout << mx << "\n";
    int pref[n] = {0};
    int suff[n] = {0};
    pref[0] = 1;
    suff[n-1] = 1;
    int mx = 1;
    for(int i = 1; i < n; i++) {
        if (v[i] > v[i-1]) {
            pref[i] = pref[i-1] + 1;
        } else {
            pref[i] = 1;
        }

        mx = max(mx, pref[i]);
    }

    for(int i = n-2; i>=0; i--) {
        if (v[i] < v[i+1]) {
            suff[i] = suff[i+1] + 1;
        } else {
            suff[i] = 1;
        }
        mx = max(mx, suff[i]);
    }
    for(int i = 0; i < n; i++) {
        if(i < n-1 && v[i] < v[i+1]) {
          mx = max(mx, pref[i] + suff[i+1]);  
        } 
        if(i < n-2 && v[i] < v[i+2]) {
         mx = max(mx, pref[i] + suff[i+2]);
        }
    }
    cout << mx << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}