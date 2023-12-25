#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
    int n,m; cin >> n >> m;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    
    auto bin = [](int mid, vector<int> v, int lim, int n) {
        for (int i = 0; i < n; i++) {
            int extra = ((2*mid + v[i]) * (2*mid + v[i]));
            lim -= extra;
            if (lim < 0) {
                return false;
            }
        }
        return true;
    };
    


    int ans = 0;
    int s = 1; int e = 1e10;
    while (s <= e) {
        int mid = s + (e - s)/2;
        if (bin(mid, v, m,n)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
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