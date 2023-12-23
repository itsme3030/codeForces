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
    int n,m; cin >> n >> m;
    int x = 1, y = 1;
    string s; cin >> s;
    int len = s.length();
    int mxx = 1, mnx = 1, mxy = 1, mny = 1;
    int ind = len;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'U') x--;
        if (s[i] == 'D') x++;
        if (s[i] == 'R') y++;
        if (s[i] == 'L') y--;
        mxx = max(mxx,x);
        mnx = min(mnx,x);
        mny = min(mny,y);
        mxy = max(mxy,y);

        if (mxy - mny >= m || mxx - mnx >= n) {
            ind = i;
            break;
        }
    } 
     x = 1, y = 1;
     mxx = 1, mnx = 1, mxy = 1, mny = 1;
    // int ind = len;
    for (int i = 0; i < ind; i++) {
        if (s[i] == 'U') x--;
        if (s[i] == 'D') x++;
        if (s[i] == 'R') y++;
        if (s[i] == 'L') y--;
        mxx = max(mxx,x);
        mnx = min(mnx,x);
        mny = min(mny,y);
        mxy = max(mxy,y);
    }
    x = 1, y = 1;
    // cout << mny << " " << mxy << " " << "\n";
    // cout << mnx << " " << mxx << "\n";
    int froml = abs(mny - y);
    int fromr = abs(mxy - y);
    int fromu = abs(mnx - x);
    int fromb = abs(mxx - x);

    // cout << froml << " " << fromr << " " << fromu << " " << fromb << "\n";
    // cout << fromu << " " << fromb << "\n";

    int inix = 1, iniy = 1;
    iniy = froml + 1;
    inix = fromu + 1;
    cout << inix << " " << iniy << "\n";
}