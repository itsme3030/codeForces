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
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    a.push_back(0);

    b.push_back(0);
    int cnt = 0;
    vector<int> con;
    for(int i = 0; i <= m; i++) {
        if (b[i] == 1) cnt++;
        else {
            con.push_back(cnt);
            cnt = 0;
        } 
    }
    b.pop_back();

    vector<int> dp(n + 2, 0);
    int row = 0;
    dp[0] = 0;
    sort(con.rbegin(), con.rend());
    int pref = 0;
    for(int i = 1; i <= n; i++) {
        if (k % i != 0) {
            dp[i] = pref;
            continue;
        }
        for(int j = 0; j < con.size(); j++) {
            if (con[j] >= k/i) {
                dp[i] += con[j] - k/i + 1;
            } else break;
        }
        int tmp = pref;
        pref += dp[i];
        dp[i] += tmp;
       
    }
    int sm = 0;
    for(int i = 0; i < n; i++) {
        if (a[i] == 0) row = 0;
        else row++;
        sm += dp[row];
    }
    cout << sm << "\n";



/*
    for(int i = 0; i <= n; i++) {

        if (a[i] == 0) {
            if (k % row == 0) {
            int cons = k/row;
            for(int j = 0; j < con.size(); j++) {
                if (con[j] >= cons) {
                     dp[row] += con[j] - cons + 1;
                    }
                }
            }
            row = 0;
        } else {
            row++;
        }
    }*/    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}