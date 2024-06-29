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
    vector<int> nums;
    for(int i = 1; i <= 1024; i++) {
        int tmp = i;
        vector<int> segs;
        for(int b = 0; b <= 10; b++) {
            if (tmp & (1ll << b)) {
                segs.push_back(1);
            } else {
                segs.push_back(0);
            }
        }
        int last_ind = segs.size() - 1;
        while (last_ind >= 0 && segs[last_ind] == 0) {
            last_ind--;
        }
        int new_one = 0;
        for(int curr = last_ind; curr >= 0; curr--) {
            new_one = new_one * 10 + segs[curr];
        }
        nums.push_back(new_one);
    }

    int count = 0;
    for(int i = 0; i < nums.size(); i++) {
        if (nums[i] <= n) count++;
        else break;
    }
    cout << count << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}