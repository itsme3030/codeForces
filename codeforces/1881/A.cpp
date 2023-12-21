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
    int n,m; cin >> n >> m;
    string s,x; cin >> x >> s;
    for (int i = 0; i < n; i++) {
        int curr = i; int y = 0; int cnt = 0;
        for (int j = i; j < i + m; j++) {
            if (x[j % n] == s[y++]) cnt++;
        }
        if (cnt == m) {
            int left = n-curr;
            cnt = 0;
            while (left < m) {
                left += n;
                n *= 2;
                cnt++;
            }
            cout << cnt << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}


