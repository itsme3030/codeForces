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
    int n,k; cin >> n >> k;
    vector<int> diff;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    int mn = INT_MAX;
    if (k == 4) {
        auto comp = [&](int x, int y) {
            return x % 2 == 0 && y % 2;
        };
        sort(v.begin(), v.end(), comp);
        int flg = 2; int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] % 4 == 0) flg -= 2;
            else if (v[i] % 2 == 0) flg--;
            else {
                flg--;
                cnt++;
            }
            if (flg == 0) break;
        }
        mn = cnt;
    } 
    for (int i = 0; i < n; i++) {
        if (v[i] <= k)
        diff.push_back((k- v[i]));
        else {
        int temp = v[i] % k;
        if (temp == 0) diff.push_back(0);
        int temp2 = k - temp;
        diff.push_back(temp2);
        }
    }
    if (diff.size() != 0)
    cout << min(mn,*min_element(diff.begin(), diff.end())) << "\n";
}


