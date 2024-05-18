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
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    // map<int, int> mappingOnPrime;
    int cnt = 1;

    // auto is_prime = [&](int tar) {
    //     for(int i = 2; i*i <= tar; i++) {
    //         if (tar % i == 0) {
    //             return false;
    //         }
    //     } 
    //     return true;
    // }; 

    // for(int i = 2; i <= 31; i++) {
    //     if (is_prime(i)) mappingOnPrime[i] = cnt++;
    // }  

    map<int, int> mappingInd;
    for(int i = 0; i < n; i++) {
        for(int j = 2; j*j <= v[i]; j++) {
            if (v[i] % j == 0) {
                mappingInd[i] = j;
                break;
            }
        } 
    }

    set<int> uni;
    map<int, int> mp;
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        if (uni.count(mappingInd[i]))
        ans[i] = mp[mappingInd[i]];
        else {
           mp[mappingInd[i]] = cnt++;
           ans[i] = mp[mappingInd[i]];  
        }
        uni.insert(mappingInd[i]);
    }
    cout << uni.size() << "\n";
    for(auto &x : ans) {
        cout << x << " ";
    } cout << "\n";

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}