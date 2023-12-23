#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,m; cin >> n >> m;
    string s; cin >> s;
    int flg = 1;
    if (s[0] - '0' < m) {
        cout << m; flg = 0;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] - '0' < m && flg) {
            cout << m; flg = 0;
        }
        cout << s[i];
    }
    if (flg == 1) cout << m;
    cout  << "\n"; 
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}