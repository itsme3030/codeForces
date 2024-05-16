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
    for(auto &x:v) cin >> x;
    sort(v.begin(), v.end());
    int cnt = 0, sm = 0;
    for(int i = 0; i < n; i++) {
        v[i] -= sm;
        if (v[i] > 1) {
            if (cnt % 2 == 0) {
                cout << "Alice\n";
                return;
            } else {
                cout << "Bob\n";
                return;
            }
        }

        if (v[i] == 1) {
            sm += 1;
            cnt++;            
        }
    }
    if (cnt % 2 == 0) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}