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
    vector<string> v(n);
    for (auto &x : v) cin >> x;
    int sm = 0;
    int temp = n/2;
    int cnt = 0;
    int temp2 = n;
    auto find = [](int x, int y,vector<string> v) -> int {
        string uprow = v[x].substr(x,y);
        string leftcol = "";
        for (int i = x; i < y + x; i++) {
            leftcol += v[i][x];
        }
        string rightcol = "";
        for (int i = x; i < y + x; i++) {
            rightcol += v[i][x + y - 1];
        }
        string bottomrow = v[x + y - 1].substr(x,y);

        int cnt = 0;
        string need = "";
        for (int i = 0; i < y; i++) {
            need += (char)max(max(uprow[i], bottomrow[y-1-i]), max(leftcol[y-1-i], rightcol[i]));
        }
        for (int i = 0; i < y; i++) {
            cnt += abs(uprow[i] - need[i]);
            uprow[i] = need[i];
        }
        leftcol[0] = uprow[0];
        for (int i = 0; i < y; i++) {
            cnt += abs(leftcol[y-1-i] - need[i]);
            leftcol[y-1-i] = need[i];
        }
        bottomrow[0] = leftcol[y-1];
        for (int i = 0; i < y; i++) {
            cnt += abs(bottomrow[y-1-i] - need[i]);
            bottomrow[y-1-i] = need[i];
        }
        rightcol[y-1] = bottomrow[y-1];
        rightcol[0] = uprow[y-1];
        for (int i = 0; i < y; i++) {
            cnt += abs(rightcol[i] - need[i]);
            rightcol[i] = need[i];
        }
        return cnt;
    };
    while (cnt < temp) {
        sm += find (cnt,temp2,v);
        temp2-=2; cnt += 1;
    }
    cout << sm << "\n";
}


