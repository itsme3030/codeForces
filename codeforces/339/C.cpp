#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

int m;
string s;
int x[10000];
int was[10000][11][11];

int go(int i, int sm, int last) {
    if (i != 0 && sm <= 0 || sm > 10) return 0;
    if (i == m) {
        cout << "YES\n";
        for(int j = 0; j < i; j++) {
            cout << x[j] << " ";
        } cout << "\n";
        return 1;
    }
    if (was[i][sm][last]) return 0;
    else was[i][sm][last] = 1;
    int take = 0;
    for(int l = 0; l < 10; l++) {
        if (l != last && s[l] == '1') {
            x[i] = l+1;
            take |= go(i+1, (l+1)-abs(sm), l);
            if (take) return 1;
        }
    }
    return 0;
}


void solve() {
    cin >> s;
    cin >> m;
    if(!go(0, 0, 10)) cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}