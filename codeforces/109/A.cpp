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
    int n; cin >> n;
    string ans;
    ans = "";
    while (n > 0) {
        if (n % 7 == 0) {
            while (n > 0) {
                ans += "7";
                n -= 7;
            }
        } else {
            n -= 4;
            ans += "4";
        }
    }
    if (n == 0) {
        cout << ans << "\n";
    } else {
        cout << -1 << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}