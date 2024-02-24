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

void find(map<int, int> &mp,int  n, vector<int> v, int ind, int &flg) {
    if (n == 0) {
        cout << mp[3] << " ";
        cout << mp[5] << " ";
        cout << mp[7] << " ";
        cout << "\n";
        flg = 1;
        return;
    }
    if (n < 0 || ind >= 3) {
        return;
    }
    
    
    if (flg) return;
    mp[v[ind]]++;
    find(mp, n - v[ind], v, ind,flg);
    if (flg) return;
    mp[v[ind]]--;
    find(mp, n, v, ind + 1,flg);
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    int n; cin >> n;
    vector<int> v(3);
    v[0] = 7;
    v[1] = 5;
    v[2] = 3;
    map<int, int> mp;
    int flg = 0;
    find(mp, n, v, 0, flg);  
    if (!flg) {
        cout << -1 << "\n";
    }
}
