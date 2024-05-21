#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int tc = 0;
void solve() {
	int n;
	cin >> n;
	vector<int> mon(n);
	for(auto &x : mon) cin >> x;
	int m;
	cin >> m;
	vector<pair<int, int>> vp(m);
	int mxh = 0;
	int mxm = *max_element(mon.begin(), mon.end());
	map<int, int> bst;
	for(int i = 0; i < m; i++) {
		cin >> vp[i].first >> vp[i].second;
		mxh = max(mxh, vp[i].first);
		bst[vp[i].second] = max(bst[vp[i].second], vp[i].first);
	}  


	// tc++;
	// if (tc == 26) {
	// 	string s;
	// 	s += to_string(n) + "|";
	// 	for(int i = 0; i < n; i++) {
	// 		s += to_string(mon[i]);
	// 		s += "|";
	// 	}
	// 	s += "|||";
	// 	s += to_string(m) + "|";
	// 	for(int i = 0; i < m; i++) {
	// 		s += (to_string(vp[i].first) +  "|" + to_string(vp[i].second) + "|"); 
	// 	}
	// 	cout << s << "\n";
	// 	return;
	// }

	if (mxh < mxm) {
		cout << -1 << "\n";
		return;
	}

	for(int i = n-1; i >= 0; i--) {
		bst[i] = max(bst[i+1], bst[i]);
	}
	int days = 0;
	int pos = 0;
	while (pos < n) {
		days++;
		int mx = 0;
		int tmp = 0;
		for(int i = pos; i < n; i++) {
			mx = max(mx, mon[i]);
			if (mx > bst[i - pos + 1]) {
				break;	
			} 
			tmp = i;
		}
		pos = tmp;
		pos++;
	}
	cout << days << "\n";


}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}
