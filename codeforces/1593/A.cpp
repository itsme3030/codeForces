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
    int a,b,c; cin >> a >> b >> c;
    int mx = max(a,max(b,c));
    if (a == mx && b == mx && c == mx) {
        cout << 1 << " " << 1 << " " << 1 <<"\n";
    } else if (a == mx && b == mx) {
        cout << 1 <<" " << 1 << " ";
        cout << mx - c + 1 << "\n";
    } else if (b == mx && c == mx) {
        cout << mx + 1 - a << " " << 1 << " " << 1 << "\n";
    } else if (a == mx && c == mx) {
        cout << 1 << " " << mx + 1 - b << " " << 1 << "\n";
    } else {
        if (a == mx) cout << 0 << " ";
        else cout << mx + 1 - a <<  " ";
    
        if (b == mx) cout << 0 << " ";
        else cout << mx + 1 - b <<  " ";

        if (c == mx) cout << 0 << " ";
        else cout << mx + 1 - c <<  " ";

        cout << "\n";
    }
}


