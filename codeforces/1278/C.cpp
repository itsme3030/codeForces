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
    int one = 0;
    int two = 0;
    vector<int> v(2*n);
    for(auto &x : v) {
        cin >> x;
        if(x == 1) one++;
        else two++;
    }
    if(two > one) {
        swap(two,one);
        for(auto &x : v) {
            if(x == 1) x = 2;
            else x = 1;
        }
    }

    int diff = one - two;
    if(diff == 0) {
        cout << 0 << "\n";
        return;
    }
    map<int,int> change;
    int mn = 1e9;
    for(int i=n-1; i>= 0; i--) {
       if(i < n-1) change[i] = change[i+1] + ((v[i] == 1) ? 1 : -1);
       else change[i] = ((v[i] == 1) ? 1 : -1);
       if(change[i] == diff) {
        mn = min(mn, (n-1-i+1));
       }
    }
    for(int i = n; i < 2*n; i++) {
        if(i > n) change[i] = change[i-1] + ((v[i] == 1) ? 1 : -1);
        else change[i] = ((v[i] == 1) ? 1 : -1);
        if(change[i] == diff) {
            mn = min(mn, (i-n+1));
        }
    }

    // for(auto &x : change) {
    //     cout << x.first  << " " << x.second << " " << "\n";
    // } cout << "\n";
    // return;
    map<int, int> freqforx;
    for(int i = n*2-1; i >= n; i--) {
        freqforx[change[i]] = (i-n+1);
    }
    for(int i = n-1; i >= 0; i--) {
        if (freqforx[diff - change[i]] != 0) {
            mn = min(mn, freqforx[diff - change[i]] + (n-1-i+1));
        }
    }
    freqforx.clear();
    for(int i = 0; i < n; i++) {
        freqforx[change[i]] = (n-1-i+1);
    }

    for(int i = n; i < 2*n; i++) {
        if(freqforx[diff - change[i]] != 0) {
            mn = min(mn ,freqforx[diff - change[i]] + (i-n+1));
        }
    }

    cout << mn << "\n";



}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}