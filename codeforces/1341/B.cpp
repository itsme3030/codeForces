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
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    vector<int> pref(n, 0);
    for(int i = 1; i < n-1; i++) {
        pref[i] += pref[i-1];
        if (v[i] > v[i-1] && v[i] > v[i+1]) {
            pref[i]++;
        }
    }  
    pref[n-1] += pref[n-2];

    int lb = n-k;
    int mxp = 1;
    for(int i = n-k; i >= 0; i--) {
        int p = pref[i+k-2] - pref[i] + 1;
        if(p >= mxp) {
            mxp = p;
            lb = i;
        }
    } 
    cout << mxp << " " << lb+1 << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}