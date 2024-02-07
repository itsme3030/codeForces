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
    string s; cin >> s;
    int n = s.length();
    map<char, int> mp;
    for (int i = 0; i < n; i++) mp[s[i]]++;

    int mx = 0;
    char ch = 'R';
    for (auto &x : mp) {
        if (x.second > mx) {
            mx = x.second;
            ch = x.first;
        }
    }

    if (ch == 'R') {
        for (int i = 0; i < n; i++) cout << 'P'; 
    } else if (ch == 'S') {
        for (int i = 0; i < n; i++) cout << 'R';
    } else {
        for (int i = 0; i < n; i++) cout << 'S';
    } cout << "\n";
}
