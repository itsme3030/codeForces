#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;


vector<int> dp(1e6 + 1);
void solve() {
   int n;
   cin >> n;
   int cnt = 0;
   int tmp = n;
   while (tmp > 0) {
      auto it = upper_bound(dp.begin(), dp.end(), tmp);
      it--;
      if (it == dp.begin()) {
         break;
      }
      cnt++;
      tmp -= *it;
   }
   cout << cnt << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   // vector<int> dp(1e6 + 1, 0);
   dp[0] = 0;
   dp[1] = 2;
   for(int i = 2; i <= 1e6; i++) {
      dp[i] = dp[i-1] + ((i)*3 - 1);
   }  
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}