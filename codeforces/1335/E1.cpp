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
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    vector<vector<int>> v(n, vector<int>(27));

    v[0][a[0]]++;
    for(int i = 1; i < n; i++) {
        v[i] = v[i-1];
        v[i][a[i]]++;
    }  

    int mx = 1;
    for(int i = 1; i <= 26; i++) {
        int find = 0;
        int l = -1, r = n;
        while (l <= r) {
            for(int j = l + 1; j < n; j++) {
                if (a[j] == i) {
                    l = j;
                    break;
                }
            }

            for(int j = r - 1; j >= 0; j--) {
                if (a[j] == i) {
                    r = j;
                    break;
                }
            }
            
            if (l == -1 || r == n || l == r || l >= r) break;
            find++;

            vector<int> temp1 = v[r];
            temp1[a[r]]--;
            vector<int> temp2 = v[l];
            
            for(int s = 1; s <= 26; s++) {
                temp1[s] -= temp2[s];
                mx = max(mx,find*2 + temp1[s]);
            }
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