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
    int n,k,m; cin >> n >> k >> m;
    string s; cin >> s;
    map<int, map<int, int>> al;
    vector<vector<int>> left(m, vector<int> (26, 0));
    vector<vector<int>> right(m, vector<int> (26, 0));

    int need = 0;
    int times = 0;
    vector<int> cnt(26, 0);
    string uni;
    for(int i = 0; i < m; i++) {
        cnt[s[i] - 'a']++;
        bool ok = true;
        for(int j = 0; j < k; j++) {
            ok &= (cnt[j] > 0);
        }
        // pr(cnt); cerr << "\n";
        if (ok) {
            times++;
            uni += s[i];
            for(int j = 0; j < k; j++) cnt[j] = 0;
        }
    }

    pr(times);
    if (times >= n) {
        cout << "YES\n";
    } else {
        int need = -1;
        for(int i = 0; i < k; i++) {
            if(cnt[i] == 0) {
                need = i; break;
            }
        }
        cout << "NO\n";
        cout << uni;
        cout << (char)('a'+need);
        // cout << char('a' + need);
        for(int i = times + 1; i < n; i++) cout << 'a';
        cout << "\n";
    }

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}
