#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    int n,x; cin >> n >> x;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    sort(v.rbegin(), v.rend());
    
    int cnt = 0;
    int sm = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
        if (sm >= x) {
            cnt++;
            count = 1;
            sm = 0;
        }
        sm = v[i] * count;
    }   
    if (sm >= x) cnt++;
    cout << cnt << "\n";
}
