#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
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
    string s; cin >> s;
    int pref[n + 1];
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + (s[i-1] - '0');
    }   
    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = s[i] - '0';

    //equation pref[1] = 1 ... pref[0] = 0 .... pref[r] - r  = pref[l-1] - l 
    int cnt = 0;
    map<int, int> mp;
    mp[pref[0] + 0]++;
    for (int i = 1; i <= n; i++) {
        cnt += mp[pref[i] - i];
        mp[pref[i] - i]++;
    }
    cout << cnt << "\n";

}
