#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int mod = 1000000007;

vector<vector<int>> ans;
void print(int& n, vector<int> tmp, int &b) {
    if (tmp.size() == 0) {
        int cnt = 1;
        for (int i = 1; i <= n; i++) {
            tmp.push_back(cnt++);
            if (cnt == b+1) cnt = 1;
        }
        ans.push_back(tmp);
    } else {
        bool ok = false;
        int cnt = 1;
        for(int i = 0; i < tmp.size(); i++) {
            if (ok) {
                cnt++;
                ok = false;
            }

            if (cnt == b+1) cnt = 1;
            if (i+1 < tmp.size()&& tmp[i] == b && tmp[i+1] == 1) {
                ok = true;
            }
            tmp[i] = cnt;
        }
        ans.push_back(tmp);
    }
    //check
    bool got = false;
    for(int l = 0; l < tmp.size(); l++) {
        if (l+1 < tmp.size() && tmp[l] == b && tmp[l+1] == 1) {
            got = true;
        }
    }

    if (!got) return;
    print(n, tmp, b);
}

void solve() {
    int n,b,d;
    cin >> n >> b >> d;
    if (b == 1 && n > 1) {
        cout << -1 << "\n";
        return;
    }
    if (d == 1 && b < n) {
        cout << -1 << "\n";
        return;
    } 
    if (n == 1) {
        for(int i = 0; i < d; i++) {
            cout << 1 << "\n";
        }
        return;
    }
    
    
    
    if (b >= n) {
        for(int j = 1; j <= d; j++) {
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << "\n";
        }
        return;
    } else {
        vector<int> tmp;
        print(n, tmp,  b);
        if (ans.size() > d) {
            cout << -1 << "\n";
            return;
        } else {
            if (ans.size() == d) {
                for(auto &x : ans) {
                    for(auto &y : x) cout << y << " ";
                    cout << "\n";
                }
                return;
            } else {
                int diff = d - ans.size();
                for(auto &x : ans) {
                    for(auto &y : x) {
                        cout << y << " ";
                    } cout << "\n";
                }

                for(int i = 0; i < diff; i++) {
                    for(int j = 0; j < n; j++) {
                        cout << 1 << " ";
                    } cout << "\n";
                }
                return;
            }
        }
    }


}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}