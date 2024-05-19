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
	for(auto &x : v) cin >> x;
	map<int, int> freq;
	for(auto &x : v) {
		freq[x]++;
	}  
	int uni = freq.size();
	if (uni > k) {
		cout << -1 <<"\n";
		return;
	}
	cout << n * k << "\n";
	for(int i = 0; i < n; i++) {
		int rest = k - uni;
		for(int j = 0; j < rest; j++) {
			cout << 1 << " ";
		}
		for(auto &x : freq) {
			cout << x.first << " ";
		} 
	} cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}