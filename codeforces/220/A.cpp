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
    int bigf = -1, bigs = -1;
    bool first = false;
    for(int i = 1; i < n; i++) {
        if (v[i-1] > v[i]) {
            if (!first) {
                first = true;
                bigf = i-1;
                bigs = i;
            } else {
                bigs = i;
                break;
            }
        }
    }
    if (bigf == bigs && bigf == -1) {
        cout << "YES\n";
        return;
    }
    int ele = v[bigf];
    while (bigf >= 0 && ele == v[bigf]) bigf--;
    if (bigf == -1) bigf++;
    if (v[bigf] != ele) bigf++;

    int ele2 = v[bigs];
    while (bigs < n && v[bigs] == ele2) bigs++;
    if (bigs == n) bigs--;
    if (v[bigs] != ele2) bigs--;

    swap(v[bigf], v[bigs]);
    bool done = true;
    for(int i = 1; i < n; i++) {
        if (v[i] < v[i-1]) {
            done = false;
            break;
        }
    }
    if (!done) {
        cout << "NO\n";
        return;
    } cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}