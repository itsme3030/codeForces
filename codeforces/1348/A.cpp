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
    vector<int> tmp;
    for(int i = 1; i <= n; i++) {
        tmp.push_back(1ll << i);
    }
    int sm1 = 0;
    int sm2 = 0;
    for(int i = 0; i < (tmp.size()/2) - 1; i++) {
        sm1 += tmp[i];
    }
    sm1 += tmp[tmp.size() - 1];
    
    for(int j = (tmp.size()/2) -  1; j < tmp.size() - 1; j++) {
        sm2 += tmp[j];
    }
    cout << sm1 - sm2 << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}