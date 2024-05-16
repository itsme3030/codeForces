#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;


void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    vector<int> idx(n);
    for (int i = 0; i < n; i++) {
        idx[v[i]-1] = i;
    }   

    int l = n;
    int r = 0;
    int i = 0;
    string ans;
    while(i < n) {
        l = min(l, idx[i]);
        r = max(r, idx[i]);
        if (r - l == i) ans += '1';
        else ans += '0';
        i++; 
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