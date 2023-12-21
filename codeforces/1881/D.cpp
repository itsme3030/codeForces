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
    map<int, int> mp;
    auto find = [](int x, map<int, int> &mp) {
        int prm = 2;
        while (x % 2 == 0 && x > 0) {
            x/=2; mp[2]++;
        }
        if (x > 0) {
            for (int i = 3; i * i <= x; i+=2) {
                while (x % i == 0 && x > 0) {
                    x /= i;
                    mp[i]++;
                }
                if (!x) break;
            }
            if (x) mp[x]++;
        }
    };
    for (auto &x : v) find(x,mp);
    for (auto &x : mp) {
        if (x.first == 1) continue;
        if (x.second % n != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}


