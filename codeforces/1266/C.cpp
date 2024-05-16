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
    int n,m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << "0" << "\n";
        return;
    }
    if (m == 1) {
        for (int i = 0; i < n; i++) {
            cout << (i+2) << "\n";
        }
        return;
    }
    int ini = n+1;
    int cnt = 1;
    for (int row = 0; row < n; row++) {
        int st = ini*(row+1);
        for (int col = 0; col < m; col++) {
            cout << st + cnt*(col) << " ";
        } cout << "\n";
        cnt++;
    }   
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}