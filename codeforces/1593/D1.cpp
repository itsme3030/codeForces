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
    vector<int> v(n); for (auto &x : v) cin >> x;
    sort(v.begin(),v.end());
    map<int, int> mp;
    
    for (auto &x : v) mp[x]++;
    int last = v[0];
    int flg = 0; int temp;
    for (auto &x : mp) {
        if (!flg) {
            flg = 1;
            continue;
        }
        if (flg == 1) {
            flg  = 2;
            temp = x.first - last;
        }else {
            temp = __gcd(temp, x.first - last);
        }
        last = x.first;
    }
    if (mp.size() == 1) {
        cout << -1 << "\n";
    } else {
        cout << temp << "\n";
    }
}


