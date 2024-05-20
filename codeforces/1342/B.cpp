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
	string s;
	cin >> s;
	int n = s.length();  
	bool isone = false, iszero = false;
	for(int i = 0; i < n; i++) {
		if (s[i] == '0') iszero = true;
		if (s[i] == '1') isone = true;
	}
	if (iszero && isone) {
		for(int i = 0; i < n; i++) {
			cout << "0" << "1";
		} cout << "\n";
	} else {
		cout << s << "\n";
	}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}