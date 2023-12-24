#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	int tar = n; int in = -1;
	for (int i = 0; i < n; i++) 
		if (v[i] == tar) {
			in = i; break;
		}
		
		if (in == 0 || in == n-1) {
		int l = 0, r = n-1;
		vector<int> left;
		vector<int> right;
		while (l <= r) {
			if (v[l] < v[r]) {
				left.push_back(v[l]); l++;
			} else {
				right.push_back(v[r]);
				r--;
			}
		} 
		reverse(left.begin(), left.end());
		for (int i = 0; i < left.size(); i++) {
			cout << left[i] << " ";
		} 
		for (int i = 0; i < right.size(); i++) cout << right[i] << " "; cout << "\n";
	} else {
		cout << -1 << "\n";
	}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}