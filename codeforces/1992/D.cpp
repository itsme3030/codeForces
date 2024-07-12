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
    int n,m,k;
    cin >> n >> m >> k;
    string s; cin >> s;
    int tot_swim = 0;
    int till = m-1;
    for(int i = 0; i < n; i++) {
        if (i < till) {
            if (s[i] == 'L') till = i+m;
        } else if (i == till) {
            if (s[i] == 'L') till = i+m;
            else if (s[i] == 'W') {
                till++;
                tot_swim++;
                if (tot_swim > k) {
                    cout << "NO\n";
                    return;
                }
            } else {
                cout << "NO\n";
                return;
            }
        } else {
            cout << "NO\n";
            return;
        }
    }
    if (till >= n) {
        cout << "YES\n";
        return;
    }
    if (s[n-1] == 'C') {
        cout << "NO\n";
        return;
    } else if (s[n-1] == 'W') {
        tot_swim++;
        if (tot_swim > k) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}