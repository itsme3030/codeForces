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
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> v;
    vector<int> b;
    vector<pair<int, int>> tpb;
    v.push_back(0);
    b.push_back(0);
    tpb.push_back({0,0});

    for(int i = 1; i <= k; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    for(int i = 1; i <= k; i++) {
        int x; cin >> x;
        b.push_back(x);
    }

    for (int i = 1; i <= k; i++) {
        tpb.push_back({b[i]-b[i-1], v[i]-v[i-1]});
    }


    auto search = [&](int tar) -> int {
        int lo = 0; int hi = v.size()-1;
        int ret = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (v[mid] > tar) {
                hi = mid - 1;
            } else {
                ret = mid;
                lo = mid + 1;
            }
        }
        return ret;
    };

    while(q--) {
        int tar;
        cin >> tar;
        int idx = search(tar);
        if (idx == v.size() - 1) {
            cout << b[idx] << " ";
        }else {
           ;
            cout << b[idx] + (tpb[idx+1].first*(tar-v[idx])/tpb[idx+1].second) << " ";
        }
    } cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}