#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int mod = 1e9 + 7;
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
     int n; cin >> n;
     vector<pair<int, int>> vp;
     if (n == 2) {
         cout << 2 << "\n";
         cout << 1 << " " << 2 << "\n";
         return;
     }
     int ele = (n + (n-2))/2;
     vp.push_back({n, n-2});
     vp.push_back({ele, n-1});
     int ind = n-3;
     while (ind > 0) {
         vp.push_back({ele, ind});
         ele = (ele + ind)/2;
         ind--;
     }
     cout << ele << "\n";
     for (auto &x : vp) {
         cout << x.first << " " << x.second << "\n";
     }
}
