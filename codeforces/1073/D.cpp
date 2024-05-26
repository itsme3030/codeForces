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
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    int sm = 0;
    for(int i = 0; i < n; i++) sm += v[i];
    priority_queue<pair<int,int>> pq;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++) {
        pq.push({v[i], i});
    }
    int buy = 0;
    int mn = *min_element(v.begin(), v.end());
    while (t >= mn) {
       int tmp = t;
       int len = 0;
       int c = 0;
       for (int i = 0; i < n; i++) {
            if (v[i] > tmp) continue;
            else {
                c += v[i];
                tmp -= v[i];
                len++;
            }
       }
       if (c == 0) break;
       int times = (t / c);
       t -= (times*c);
       buy += (len*times);
    }
    cout << buy << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}