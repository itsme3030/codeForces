#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}


void solve() {
    int n,m; cin >> n >> m;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    int k; cin >> k;
    vector<int> b(k);
    for (auto &x : b) cin >> x;

    map<int, int> mp1,mp2;
    
    vector<pair<int, int>> vp;
    auto find = [&](map<int, int> &mp, int x, int div) {
        int cnt = 1; int i = 1;
        while (x % div == 0) {
            x /= div;
            cnt = cnt * div;
        }
        mp[x] += cnt;
        vp.push_back({x,cnt});
    };
    int flg = 0;
    auto find2 = [&](map<int, int> &mp, int x, int div, int &it) {
        int cnt = 1; int i = 1;
        while (x % div == 0) {
            x /= div;
            cnt = cnt * div;
        }
        
        mp[x] += cnt;
        // cout << "start : " << it << " " << cnt  << " " <<  x << " "<< vp[i].first << " " << vp[i].second << "\n";
        while (cnt > 0) {
            if (vp[it].second == 0) it++;
            if (it >= n) {
                cout << "No\n";
                flg = 1;
                return;
            }
            if (vp[it].first != x) {
                cout << "No\n";
                flg = 1;
                return;
            } else {
                if (vp[it].second >= cnt) {
                    vp[it].second -= cnt;
                    cnt = 0;
                }else {
                    cnt -= vp[it].second;
                    vp[it].second = 0;
                }
            }
        }

    };

    for (int i = 0; i < n; i++) {
        find(mp1, v[i], m);
    }

    int x = 0;
    for (int i = 0; i < k; i++) {
        find2(mp2, b[i], m, x);
        if (flg) {
            return;
        }
    }

    if (mp1.size() != mp2.size()) {
        cout << "No\n";
        return;
    }
    for (auto &x : mp1) {
        if (x.second != mp2[x.first]) {
            cout << "No\n";
            return;
        }
    }
   cout << "Yes\n";
}