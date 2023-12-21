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
   int tt = 1; cin >> tt; while (tt--)
    solve();
    return 0;
}
//-----------------------------------------------------------------------
void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;

	vector<int> dp(n + 1);
	dp[0] = 0; int ans = 0;
	for (int i = 1; i < n; i++) {
		if (v[i-1] <= v[i]) {
			int curr = dp[i-1]; int x = v[i];
			while (curr > 0 && v[i-1] <= x/2) {
				x/=2; curr--;
			}
			ans += curr;
			dp[i] = curr;
		} else {
			int curr = dp[i-1]; int x = v[i];
			while (v[i-1] > x) {
				x*=2; curr++;
			}
			dp[i] = curr;
			ans += curr;
		}
	}
	cout << ans << "\n";
}


