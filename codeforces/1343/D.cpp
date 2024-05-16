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
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  int pref[2*k+2] = {0};
  int suff[2*k+2] = {0};

  int l = 0, r = n-1;
  while(l <= r) {
  	int sm = v[l] + v[r];
  	pref[sm + 1] += 1;
  	pref[k + max(v[l], v[r]) + 1] += 1;
  	suff[sm - 1] += 1;
  	suff[min(v[l], v[r])] += 1;

  	l++, r--;
  } 

  for (int i = 1; i <= 2*k; i++) {
  	pref[i] += pref[i-1];
  }
  for (int i = 2*k; i >= 1; i--) {
  	suff[i] += suff[i+1];
  }

  int mn = 1e10;
  for (int i = 1; i <= 2*k; i++) {
  	mn = min(mn, pref[i] + suff[i]);
  }
  cout << mn << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}