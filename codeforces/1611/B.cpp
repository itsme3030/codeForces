#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
    int n,m; cin >> n >> m;
    int sm = n + m;
    int mx = sm/4;
    cout << min(mx,min(n,m)) << "\n";  
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}