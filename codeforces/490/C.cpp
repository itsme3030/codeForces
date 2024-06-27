#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int a,b;
    cin >> a >> b;
    vector<int> pref(n+1);
    vector<int> suff(n+1);
    pref[0] = 0;
    suff[n] = 0;

    for(int i = 1; i <= n; i++) {
        pref[i] = (pref[i-1]*10 + (s[i-1]-'0')) % a;
    }
    int p = 1;
    for(int i = n-1; i >= 0; i--) {
        suff[i] =  (suff[i+1] + (s[i]-'0')*p) % b;
        p=(p*10) % b;
    }
    bool ok = false;
    int till = 0;
    for(int i = 1; i <= n-1; i++) {
        if (s[i] != '0') {
            if (pref[i] == 0 && suff[i] == 0) {
                ok = true;
                till = i;
                break;
            }
        }
    }
    if (!ok) cout << "NO\n";
    else {
        cout << "YES\n";
        for(int i = 0; i < till; i++) cout << s[i];
        cout << "\n";
        for(int i = till; i < n; i++) cout << s[i];
        cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}