#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
    int n; cin >> n;
    vector<int> v(n-1);
    for (auto &x : v) cin >> x;
    cout << v[0] << " ";
    for (int i = 1; i < n-1; i++) {
        cout << min(v[i], v[i-1]) << " ";
    } 
    cout << v[n-2] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}