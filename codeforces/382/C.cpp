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
    set<int> dif;
    sort(v.begin(), v.end());
    for(int i = 1; i < n; i++) {
        dif.insert(v[i] - v[i-1]);
    }
    if (dif.size() == 0) {
        cout << -1 << "\n";
        return;
    }

    if (dif.size() > 2) {
        cout << 0 << "\n";
        return;
    }

    int ff = *dif.begin();
    int la = *dif.rbegin();
    if (ff == la) {
        
        if (ff == 0) {
            cout << 1 << "\n";
            cout << v[0] << "\n";
            return;
        }
        
        if (n == 2) {
            int curr_diff = ff;
            if (curr_diff % 2 == 0) {
                cout << 3 << "\n";
                cout << v[0] - ff << " " << v[0] + curr_diff/2 << " " << v[n-1] + la << "\n";
                return;
            }
        }

        cout << 2 << "\n";
        cout << v[0] - ff << " " << v[n-1] + la << "\n";
        return;
    } else {
        if (ff*2 == la) {
            int times = 0;
            int fele = -1, sele = -1;
            for(int i = 1; i < n; i++) {
                if (v[i] - v[i-1] == la) {
                    times++;
                    sele = v[i];
                    fele = v[i-1];
                }
            }
            if (times > 1) {
                cout << 0 << "\n";
                return;
            } else {
                int mid = la/2;
                cout << 1 << "\n";
                cout << fele + mid << "\n";
                return;
            }
        } else {
            cout << 0 << "\n";
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}