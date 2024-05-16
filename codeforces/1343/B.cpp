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
    int n;
    cin >> n;
    if (n % 4 != 0) {
        cout << "NO\n";
        return;
    }  
    cout << "YES\n";
    int fEven = 2;
    for (int i = 0; i < n/2; i++) {
        if (i % 2 == 0) {
            cout << fEven << " ";
            fEven += 2;
        } else {
            cout << fEven << " ";
            fEven += 4;
        }
    }
    int sodd = 1;
    for (int i = n/2; i < n; i++) {
        if ((i-n/2) % 2 == 0) {
            cout << sodd << " ";
            sodd += 4;
        } else {
            cout << sodd << " ";
            sodd += 2;
        }
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}