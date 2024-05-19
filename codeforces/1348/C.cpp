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
	string s;
	cin >> s;
	map<char, int> mp;
	for(int i = 0; i < n; i++) {
		mp[s[i]]++;
	}  
	if(mp.size() == 1) {
		pair<char, int> f = *mp.begin();
		int size = f.second/k + (f.second % k != 0);
		for(int i = 0; i < size; i++) {
			cout << f.first;
		}
		cout << "\n";
		return;
	}

	int diff = 0;
	int cnt = k;
	string final;
	bool ok = false;
	for(auto &x : mp) {
		if (x.second < k) {
			k -= x.second;
			diff++;
		}else {
			diff++;
			final += x.first;
			x.second -= k;
			if(x.second == 0) ok = true;
			break;
		}
	}

	if(diff > 1) {
		cout << final << "\n";
		return;
	}

	if (mp.size() == 2 && ok) {
		pair<int, int> last = *mp.rbegin();
		char ch = last.first;
		int freq = last.second;
		int size = freq/k + (freq % k != 0);
		for(int j = 0; j < size; j++) {
			final += ch;
		}
	}
	else {
		for(auto &x : mp) {
			if (x.first >= final[0]) {
				for(int i = 0; i < x.second; i++) {
					final += x.first;
				}
			} 
		}
	}
	cout << final << "\n";

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}