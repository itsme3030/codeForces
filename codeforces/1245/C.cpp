#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int mod = 1000000007;
void solve() {
	string s;
	cin >> s;
	int n = s.length();
	if (s.find('m') != string::npos || s.find('w') != string::npos) {
		cout << 0 << "\n";
		return;
	}
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for(int i = 1; i <= n; i++) {
		if (i > 0 && ((s[i-1] == 'n' && s[i-2] == 'n') || (s[i-1] == 'u' && s[i-2] == 'u'))) {
			dp[i] += (dp[i-1] + dp[i-2]) % mod;
			dp[i] %= mod;
		} else {
			dp[i] += (dp[i-1] % mod);
			dp[i] %= mod;
		}
	}

	cout << dp[n] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}