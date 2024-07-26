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
    int n,m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m)), b(n, vector<int> (m));
    for(auto &x : a) for(auto &y : x) cin >> y;
    for(auto &x : b) for(auto &y : x) cin >> y;

    vector<vector<int>> tmp = a;
    vector<vector<int>> tmp2 = b;
    set<vector<int>> st1, st2, st3, st4;
    for(int i = 0; i < n; i++) {
        sort(tmp[i].begin(), tmp[i].end());
        sort(tmp2[i].begin(), tmp2[i].end());
        st1.insert(tmp[i]), st2.insert(tmp2[i]);
    }

    vector<vector<int>> tmp3(m, vector<int> (n)), tmp4(m, vector<int> (n));
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            tmp3[j][i] = a[i][j];
            tmp4[j][i] = b[i][j];
        }
        sort(tmp3[j].begin(), tmp3[j].end());
        sort(tmp4[j].begin(), tmp4[j].end());
        st3.insert(tmp3[j]), st4.insert(tmp4[j]);
    }

  
    if (st1 == st2 && st3 == st4) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}
