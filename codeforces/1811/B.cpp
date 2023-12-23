#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,x1,y1,x2,y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    int disk1 = min(min(n + 1 - x1,x1),min(y1,n + 1 - y1));
    int disk2 = min(min(n + 1 - x2, x2), min(y2, n + 1 - y2));
    int diff = abs(disk1 - disk2);
    cout << diff << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}