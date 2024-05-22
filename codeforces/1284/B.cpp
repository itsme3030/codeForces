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
    vector<vector<int>> v(n);
    vector<vector<int>> actual;
    int cnt = n*n;
    for(int i = 0; i < n ;i++) {
        int x;
        cin >> x;
        v[i].resize(x);
        for(int j = 0; j < x; j++) {
            cin >> v[i][j];
        }
        bool ok = false;
        int mini = 1e9;
        for(int j = 0; j < x; j++) {
            if(v[i][j] > mini) {
                ok = true;
                break;
            }
            mini = min(mini, v[i][j]);
        }

        if(!ok) {
            actual.push_back(v[i]);
        }
    }

    vector<int> mn(actual.size(), 1e12);
    vector<int> mx(actual.size(), 0);
    for(int i = 0; i < actual.size(); i++) {
        for(int j = 0; j < actual[i].size(); j++) {
            mn[i] = min(mn[i], actual[i][j]);
            mx[i] = max(mx[i], actual[i][j]);
        }
    }

    sort(mn.begin(), mn.end());
    sort(mx.begin(), mx.end());

    for(int i = 0; i < actual.size(); i++) {
        auto it = upper_bound(mx.begin(), mx.end(), mn[i]);
        cnt -= (it - mx.begin());
        // it = lower_bound(mn.begin(), mn.end(), mx[i]);
        // cnt -= (mn.end() - it);
    }
    cout << cnt << "\n";



    // vector<int> mx(actual.size());
    // vector<int> mnn(actual.size(), 1e12);

    // for(int i = 0; i < actual.size(); i++) {
    //     for(int j = 0; j < actual[i].size(); j++) {
    //         mnn[i] = min(mnn[i],actual[i][j]); 
    //         mx[i] = max(mx[i], actual[i][j]);
    //     }
    // }
    // sort(mx.begin(), mx.end());
    // for(int i = 0; i < actual.size(); i++) {
    //     auto it = upper_bound(mx.begin(), mx.end(), mnn[i]);
    //     cnt += mx.end() - it;
    // }
    // cout << cnt << "\n";

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}