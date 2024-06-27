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
    int n,l,r;
    cin >> n >> l >> r;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    int lo = 0, hi = 0;
    int sm = 0;
    int ans = 0;
    while (hi < n) {
        sm += v[hi];
        if (sm >= l && sm <= r) {
            sm = 0;
            ans++;
        }

        while (sm > r && lo <= hi) {
            sm -= v[lo];
            if (sm >= l && sm <= r) {
                sm = 0, ans++;
                break;
            }
            lo++;
        }
        hi++;
        if (sm == 0) {
            lo = hi;
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}