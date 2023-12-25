#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
 vector<int> v(3);
 for(auto &x : v) cin >> x;
 sort(v.begin(), v.end());
 if (v[2] + v[1] >= 10) cout << "YES\n";
 else cout << "NO\n";  
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}