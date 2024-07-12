#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define lcd(a,b) (a*b)/__gcd(a,b) 
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    int x,a,y,b; cin >> x >> a >> y >> b;
    int k; cin >> k;
    int lo = 1, hi = n/a+n/b-n/lcd(a,b);

    if (y > x) {
        swap(x,y);
        swap(a,b);
    }

    int ans = -1;
    for(int i = 0; i < n; i++) {
        v[i]/=100;
    }
    sort(v.rbegin(), v.rend());

    auto check = [&](int tar) -> int {
		int xpoi = 0, ypoi = 0;
		int mixpoi = 0;
		int c = lcd(a,b);
		int tmpa = a;
		int tmpb = b;
		int tmpc = c;
		int ini = 1;
		while (ini <= tar) {
			if (tmpc == tmpa && tmpc == tmpb) {
				mixpoi++;
				tmpa += a;
				tmpb += b;
				tmpc += c;
			} else if (tmpa < tmpb) {
				xpoi++;
				tmpa += a;
			} else if (tmpb < tmpa) {
				ypoi++;
				tmpb += b;
			}
			ini++;
		} 
		
        int count = 0;
        for(int i = 0; i < mixpoi; i++) count += (v[i] * (x+y));
        for(int i = mixpoi; i < mixpoi + xpoi; i++) {
            count += v[i] * x;
        }
        for(int i = mixpoi + xpoi; i < mixpoi + xpoi + ypoi; i++) {
            count += v[i] * y;
        }
        return count;
    };


    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid) >= k) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    if (ans == -1) {
        cout << -1 << "\n";
        return;
    } else {
        int cnt = 0;
        int tmpa = a, tmpb = b;
        for(int i = 0; i < n; i++) {
			if ((i+1) % a == 0 || (i+1) % b == 0) {
				cnt++;
				if (cnt == ans) {
					cout << (i+1) << "\n";
					return;
				}
			}
		}
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