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
    int n;
    cin >> n;
    int tmp = n;
    int newone = 1;
    set<int> st;
    int cnt = 0;
    for(int i = 2; i * i <= n; i++) {
        while (tmp % i == 0 && tmp >= 1) {
            tmp/=i;
            newone*=i;
            if (cnt < 2 && !st.count(newone)) {
                st.insert(newone);
                cnt++;
                newone = 1;
            }
        }
    }
    if(tmp > 1) newone *= tmp;
    if (newone > 1) 
    st.insert(newone);
    if (st.size() < 3) {
        cout << "NO\n";
        return;
    } else {
        cout << "YES\n";
        for(auto &x : st) {
            cout << x << " ";
        } cout << "\n";
    }
    // if (tmp > 1) fact[tmp]++;



    // auto bin_expo = [&](int x, int y) -> int {
    //     int res = 1;
    //     while (y > 0) {
    //         if (y % 2) {
    //             res = res*x;
    //         }
    //         y/=2;
    //         x*=x; 
    //     }
    //     return res;
    // };

    // if (fact.size() == 1) {
    //     if (tot < 6) {
    //         cout << "NO\n";
    //         return;
    //     } else {
    //         pair<int, int> p1 = *fact.begin();
    //         cout << bin_expo(p1.first, 1) << " "; 
    //         cout << bin_expo(p1.first, 2) << "  ";
    //         cout << bin_expo(p1.first, p1.second - 3) << "  "; 
    //     }
    // } else if (fact.size() == 2) {
    //     set<int> st;

    // }







    // if (fact.size() < 3) {
    //     cout << "NO\n";
    //     return;
    // } else {
    //     cout << "YES\n";
    //     int cnt = 1;
    //     int sm = 0;
    //     for(auto &x : fact) {
    //         if (cnt < 3) {
    //             cout << bin_expo(x.first, x.second) << " ";
    //         } else {
    //             sm += bin_expo(x.first, x.second); 
    //         }
    //         cnt++;
    //     }

    //     cout << sm << " ";
    // } cout << "\n";


}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}