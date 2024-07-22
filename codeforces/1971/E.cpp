#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define lcd(a,b) __gcd(a,b)/(a*b)
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

void pr(int x) {cerr << x;}
void pr(long x) {cerr << x;}
//void pr(long long x) {cerr << x;}
void pr(unsigned x) {cerr << x;}
void pr(unsigned long x) {cerr << x;}
void pr(unsigned long long x) {cerr << x;}
void pr(float x) {cerr << x;}
void pr(double x) {cerr << x;}
void pr(long double x) {cerr << x;}
void pr(char x) {cerr << '\'' << x << '\'';}
void pr(const char *x) {cerr << '\"' << x << '\"';}
void pr(const string &x) {cerr << '\"' << x << '\"';}
void pr(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void pr(const pair<T, V> &x) {cerr << '{'; pr(x.first); cerr << ','; pr(x.second); cerr << '}';}
template<typename T>
void pr(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), pr(i); cerr << "}";}
void pr() {cerr << "]\n";}
template <typename T, typename... V>
void pr(T t, V... v) {pr(t); if (sizeof...(v)) cerr << ", "; pr(v...);}
#ifndef ONLINE_JUDGE
#define pr(x...) cerr << "[" << #x << "] = "; pr(x)
#else
#define pr(x...)
#endif
int mod = 1000000007;

int bin_expo(int a, int b, int mod) {
    int res = 1;
    while(b > 0) {
        if (b % 2) {
            res = res * a % mod;
        }
        b/=2;
        a = a * a % mod;
    }
    return res;
}

int inv(int a, int mod) {
    return bin_expo(a, mod - 2, mod) % mod;
}

void solve() {
    int n,k,q; cin >> n >> k >> q;
    vector<int> a(k), t(k);
    for(auto &x : a) cin >> x;
    for(auto &x : t) cin >> x;
    while(q--) {
        int dis; cin >> dis;
        int lo = 0, hi = k-1;
        int ans = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (a[mid] <= dis) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (ans == -1) {
            cout << (int)(dis*t[0])/a[0] << " "; 
        } else {
            int nxt = ans + 1;
            if (nxt >= k) {
                cout << t[k-1] << " ";
            } else {
                double speed = ((a[nxt] - a[ans]) * 1.0) / (t[nxt] - t[ans]);
                cout <<  (((dis - a[ans])*(t[nxt] - t[ans])) / (a[nxt] - a[ans])) + t[ans] << " ";
            }
        }
    }cout << "\n";

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}
