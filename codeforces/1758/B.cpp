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
  if (n%2) {
    for(int i = 0; i < n; i++) {
      cout << 1 << " ";
    } cout << "\n";
    return;
  } else {
    cout << 3 << " " << 1 << "\n";
    for(int i = 0; i < n-2; i++) {
      cout << 2 << " ";
    } cout << "\n";
    return;
  }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}