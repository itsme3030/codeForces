#include<bits/stdc++.h>
using namespace std;
long long t = 0;
#define ll    long long int
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
#define int ll
void solve();
int bin_expo(int a, int b) {
    int ans = 1;
    while (b > 0) { 
         if (b % 2)  
            ans = ans * a;
         b/=2; 
         a = a * a; 
     } 
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}
//---------------------------solution----------------------------------------//
void solve() {
    int n; cin >> n;
    vector<pair<int, char>> vp(n);
    for (int i = 0; i < n; i++) {
        cin >> vp[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> vp[i].second;
    }
    multiset<int> r;
    multiset<int> b;
    int red = 0, blue = 0;
    for (int i = 0; i < n; i++) {
        if (vp[i].second == 'R') { r.insert(vp[i].first); red++; }
        if (vp[i].second == 'B') { b.insert(vp[i].first); blue++; }
    }
    int reqred = n - red + 1;
    int reqblue = reqred - 1;

    for (int i = 1; i <= reqblue; i++) {
        auto it = b.begin();
        if (i > *it) {
            cout << "NO\n";
            return;
        }
        b.erase(it);
    }

    for (int i = reqred; i <= n; i++) {
        auto it = r.begin();
        if (i < *it) {
            cout << "NO\n";
            return;
        }
        r.erase(it);
    }
    cout << "YES\n";
}







