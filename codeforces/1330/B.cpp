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
	map<int, int> st1;
	map<int, int> st2;
	for(int i = 0; i < n; i++) {
		st2[(v[i])]++;
	}   
	vector<pair<int, int>> ans;
	for(int i = 0; i < n-1; i++) {
		st2[v[i]]--;
		if (st2[v[i]] == 0) {
			st2.erase(v[i]);
		}
		st1[v[i]]++;
		int len1 = i + 1;
		int len2 = n - len1;

		int last = (*st2.rbegin()).first;
		if (last == len2 && st2.size() == len2 && (*st1.rbegin()).first == len1 && st1.size() == len1) {
			ans.push_back({len1, len2});
		}
	}

	cout << ans.size() << "\n";
	for(auto &x : ans) {
		cout << x.first << " " << x.second << "\n";
	}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}