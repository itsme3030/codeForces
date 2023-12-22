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
    auto count = [](int n) -> int {
        int cnt = 0;
        while (n > 0 && n % 5 == 0) {
            n/=5;  cnt ++;
        }
        return cnt;
    };
    int temp1 = INT_MAX; int temp2 = INT_MAX;
    string s = to_string(n);
    int len = s.length() - 1;
    int mn = INT_MAX;
    auto find = [](char a, char b, string s) -> int {
        int in1 = INT_MAX, in2 = INT_MAX;
        for (int i = 0; i < s.length(); i++) {
            if(s[i] == a) {
                in1 = i;
                break;
            }
        }
        if (in1 != -1) {
            for (int i = in1 + 1; i < s.length(); i++) {
                if (s[i] == b) {
                    in2 = i;
                    break;
                }
            }
        }
        return in2 - 1;
    };
    reverse(s.begin(), s.end());
    mn = min(mn, find('0','0',s));
    mn = min(mn, find('0','5',s));
    mn = min(mn, find('5','7',s));
    mn = min(mn, find('5','2',s));
    cout << mn << "\n";
}


