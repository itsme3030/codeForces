#include<bits/stdc++.h>
using namespace std;
long long t = 0;
#define ll    long long int
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
#define int ll
//-----------------------------------------------------------------------
void solve();
int bin_expo(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b % 2) {
            ans = ans * a;
        } b/=2;
        a = a * a;
    } return ans;
}
//-----------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
    solve();
    return 0;
}
//-----------------------------------------------------------------------
void solve() {
	int n; cin >> n;
	multiset<int> left;
	multiset<int> right;
	for (int i = 0; i < n; i++) {
		char ch; int x,y; cin >> ch >> x >> y;
		if (ch == '+') {
			left.insert(x); right.insert(y);
			int l2 = *left.rbegin();
			int r1 = *right.begin();
			if (l2 > r1) {
				cout << "YES\n";
			} else cout << "NO\n";
		}else {
			auto it = left.find(x);
			left.erase(it);
			auto it2 = right.find(y);
			right.erase(it2);
			if (left.empty() || right.empty()) {
				cout << "NO\n";
				continue;
			}
			int l2 = *left.rbegin();
			int r1 = *right.begin();
			if (l2 > r1) {
				cout << "YES\n";
			} else cout << "NO\n";
		}
	}
}


