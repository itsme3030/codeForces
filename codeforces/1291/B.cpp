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
   vector<int> v(n);
   for(auto &x : v) cin >> x;
   if (n == 1) {
      cout << "Yes\n";
      return;
   }  
   int ext = 0;
   bool isinc = true;
   for(int i = 0; i < n; i++) {
      if (v[i] >= i && isinc) continue;
      if (isinc) {
         if (v[i-1] <= (n-i-1)) {
            cout << "No\n";
            return;
         }
      }
      isinc = false;

      if (v[i] >= (n-i-1)) continue;

      cout << "No\n";
      return;
   }

   cout << "Yes\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}