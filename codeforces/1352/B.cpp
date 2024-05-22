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
    int n,k;
    cin >> n >> k;
    if (n >= 2*k) {
        if(n % 2 == 0) {
            cout << "YES\n";
            for(int i = 0; i < k-1; i++) {
                cout << 2 << " ";
                n -= 2;
            }
            cout << n << "\n";
        }else {
            if (k % 2) {
                cout << "YES\n";
                for(int i = 0; i < k-1; i++) {
                    cout << 1 << " ";
                    n -= 1;
                } 
                cout << n << "\n";
            }else {
                cout << "NO\n";
                return;
            }
        }
    } else {
        if (n >= k && k%2 == n%2) {
            cout << "YES\n";
                for(int i = 0; i < k-1; i++) {
                    cout << 1 << " ";
                    n -= 1;
                } 
                cout << n << "\n";
        }else {
                cout << "NO\n";
                return;
        }
    }  
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}