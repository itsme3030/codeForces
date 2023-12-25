#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}


void solve() {
    int n,m; cin >> n >> m;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    int cnt = 1; int mx = 1;
    for (int i = 1; i < n; i++) {
        if (abs(v[i] - v[i-1]) <= m) {
            cnt++;
        }else {
            cnt = 1;
        }
        mx = max(mx, cnt);
    }
    mx = max(mx, cnt);
    cout << n - mx << "\n";
}