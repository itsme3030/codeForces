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
    int nb,ns,nc;
    cin >> nb >> ns >> nc;
    int pb, ps, pc;
    cin >> pb >> ps >> pc;
    int r; cin >> r;

    map<char,int> mp;
    for(int i = 0; i < n; i++) {
        mp[s[i]]++;
    }
    int tot_per_hb = 0;
    tot_per_hb += mp['B']*pb;
    tot_per_hb += mp['S']*ps;
    tot_per_hb += mp['C']*pc;

    int i = 0;
    int cnt = 0;
    while (i < 100 && r >= 0) {
        if (nb >= mp['B']) {
            nb -= mp['B'];
        } else {
            int reqb = mp['B'] - nb;
            if (r >= reqb*pb) {
                r -= (reqb*pb);
            } else {
                break;
            }
            nb = 0;
        }

        if (ns >= mp['S']) {
            ns -= mp['S'];
        } else {
            int reqs = mp['S'] - ns;
            if (r >= reqs*ps) {
                r -= reqs*ps;
            }  else {
                break;
            }
            ns = 0;
        }

        if (nc >= mp['C']) {
            nc -= mp['C'];
        } else {
            int reqc = mp['C'] - nc;
            if (r >= reqc*pc) {
                r -= (reqc*pc);
            } else {
                break;
            }
            nc = 0;
        }
        cnt++;
        i++;
    }

    cnt += (r/tot_per_hb);
    cout << cnt << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}