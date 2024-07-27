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
	int tmp = n;
	int cnt = -1;
	vector<int> ans;
	while (tmp > 0) {
		int num = tmp % 10;
		tmp/=10;
		cnt++;
		if (num == 0) continue;
		ans.push_back(num * pow(10, cnt));
	}  
	cout << ans.size() << "\n";
	for(auto &x : ans) {
		cout << x << " ";
	} cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}