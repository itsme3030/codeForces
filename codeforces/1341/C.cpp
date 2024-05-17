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
	vector<int> vis(n, 0);
	for(auto &x : v) cin >> x;
	map<int, int> idx;
	for(int i = 0; i < n; i++) {
		idx[v[i]] = i;
	}

	for(int req = 1; req <= n; req++) {
		int index = idx[req];
		int last = -1;
		for(int i = index; i < n; i++) {
			if (i > index && vis[i] == 1) {
				last = v[i-1];
				break;
			}
			if (i > index && v[i] - 1 != v[i-1]) {
				cout << "No\n";
				return;
			} else {
				vis[i]=1;
			}
		}
		if (last == -1) continue;
		else {
			req = last;
		}
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