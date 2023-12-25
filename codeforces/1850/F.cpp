#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    map<int, int> freq;
    for (auto &x :  v) freq[x]++;

    map<int, int> freqonstep;
    
    for (auto &x : freq) {
        int temp = x.first;
        while (temp <= n) {
            freqonstep[temp] += x.second;
            temp += x.first;
        }
    }

    int mx = 0;
    for (auto &x : freqonstep) {
        if (x.first <= n) {
            mx = max(mx, x.second);
        }
    }

    cout << mx << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}