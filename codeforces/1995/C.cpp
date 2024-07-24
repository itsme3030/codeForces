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
    int n; cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    bool big = false;
    for(int i = 0; i < n; i++) {
        if (v[i] == 1) {
            if (big) {
                cout << -1 << "\n";
                return;
            }
        } 
        if (v[i] > 1) big = true;
    }
    vector<int> adv(n, 0);
    for(int i = 1; i < n; i++) {
        int curr = v[i], p_curr = v[i-1];
        if (p_curr <= curr) {
            if (p_curr == 1) {
                adv[i] = 1e9; continue;
            }

            int times = 0;
            while(p_curr * p_curr <= curr) {
                p_curr *= p_curr;
                times++;
            }
           
            adv[i] = times;
        } else {
            if (curr == 1) {
                adv[i] = -1*1e9;
                continue;
            }

            int times = 0;
            while(curr < p_curr) {
                curr *= curr;
                times++;
            }
            adv[i] = -1*times;
        }
    }

    // pr(adv); cout << "\n";

    int sm = 0;
    int pre = 0;
    vector<int> dp(n, 0);
    for(int i = 1; i < n; i++) {
        if (adv[i] < 0) {
            dp[i] += (dp[i-1] + -1*adv[i]);
        }else {
            dp[i] = max(0ll, dp[i-1] - adv[i]);
        }
    }
    cout << accumulate(dp.begin(), dp.end(), 0ll) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}
