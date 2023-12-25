#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
    int n; cin >> n; int q = -1; int ans = -1;
    for (int i = 0; i < n; i++) {
        int x,y; cin >> x >> y;
        if (x > 10) continue;
        if (y > q) {
            q = y;
            ans = i + 1;
        }
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