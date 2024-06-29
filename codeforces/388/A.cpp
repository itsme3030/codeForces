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
    multiset<int> ms1;
    for(int i = 0; i < n; i++) {
        ms1.insert(v[i]);
    }
    int cnt = 0;
    while(!ms1.empty()) {
        cnt++;
        int ff = *ms1.begin();
        ms1.erase(ms1.begin());
        int ele = 1;
        while (!ms1.empty()) {
            auto it = ms1.lower_bound(ele);
            if (it == ms1.end()) break;
            else {
                ele++;
                ms1.erase(it);
            }
        }
    }
    cout << cnt << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}