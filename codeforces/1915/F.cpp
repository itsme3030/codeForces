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
    int n; cin >> n;
    vector<pair<int,int>> vp(n);
    for(int i = 0; i < n; i++) cin >> vp[i].first >> vp[i].second;
    auto comp = [&](pair<int,int> p1, pair<int,int> p2) {
        return p1.first > p2.first;
    };
    sort(vp.begin(), vp.end(), comp);
    int ans = 0;
    set<int> tmp;
    ordset st;
    st.insert(vp[0].second);
    for(int i = 1; i < n; i++) {
        ans += st.order_of_key(vp[i].second);
        st.insert(vp[i].second);
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