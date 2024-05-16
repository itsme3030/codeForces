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
 	for (auto &x : v) cin >> x;
 	bool pos = (v[0] > 0);

 	int sm = 0;
 	int mpos = 0;
 	int mneg = -1*1e10;
 	int last = -1;
 	for (int i = 0; i < n; i++) {
 		if (v[i] > 0) {
 			if (mneg != -1*1e10)
 			sm += mneg;
 			mneg = -1*1e10;
 			mpos = max(mpos, v[i]);
 		} else {
 			sm += mpos;
 			mpos = 0;
 			mneg = max(mneg, v[i]);
 		}
 	}
 	if (mneg != -1*1e10) sm += mneg;
 	else sm += mpos;
 	cout << sm << "\n";  
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}