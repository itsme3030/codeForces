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
    vector<pair<int, int>> vp(n);
    for(int i = 0; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        vp[i].first = n1, vp[i].second = n2;
    }
    sort(vp.begin(), vp.end());
    set<int> st;
    int curr = 0;
    st.insert(vp[0].second);
    for(int i = 1; i < n; i++) {
        int mx = *st.rbegin();
        if (mx > vp[i].second) {
            curr++;
        }
        st.insert(vp[i].second);
    }
    cout << curr << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}