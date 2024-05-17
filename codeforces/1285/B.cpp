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
    int sm = 0;
    for(auto &x : v) sm += x;
    int mxsm = 0;
    int tot = 0;
    for(int i = 0; i < n-1; i++) {
        tot += v[i];
        if (tot > 0) {
            mxsm = max(mxsm, tot);
        } else {
            tot = 0;
        }
    }   
    tot = 0;
    for(int i = 1; i < n; i++) {
        tot += v[i];
        if(tot > 0) mxsm = max(mxsm, tot);
        else tot = 0;
    }

    cout << (mxsm >= sm ? "NO\n" : "YES\n");
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}