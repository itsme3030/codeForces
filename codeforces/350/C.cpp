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
    vector<pair<int, int>> vp(n);
    for(int i = 0; i < n; i++) {
        cin >> vp[i].first >> vp[i].second;
    }
    vector<pair<int, int>> div[4];
    for(int i = 0; i < n; i++) {
        if (vp[i].first >= 0 && vp[i].second >= 0) {
            div[0].push_back(vp[i]);
        } else if (vp[i].first >= 0 && vp[i].second <= 0) {
            div[1].push_back(vp[i]);
        } else if (vp[i].first <= 0 && vp[i].second <= 0) {
            div[2].push_back(vp[i]);
        } else {
            div[3].push_back(vp[i]);
        }
    }

    auto comp1 = [&](pair<int, int> p1, pair<int, int> p2) {
        if (p1.first == p2.first) {
            return  p1.second < p2.second;
        }
        return  p1.first < p2.first;
    };
    auto comp2 = [&](pair<int, int> p1, pair<int, int> p2) {
        if (p1.first == p2.first) {
            return p1.second > p2.second;
        }
        return p1.first < p2.first;
    };
    auto comp3 = [&](pair<int, int> p1, pair<int, int> p2) {
        if (p1.first == p2.first) {
            return p1.second > p2.second;
        }
        return  p1.first > p2.first;
    };
    auto comp4 = [&](pair<int, int> p1, pair<int, int> p2) {
        if (p1.first == p2.first) {
            return p1.second < p2.second;
        }
        return p1.first > p2.first;
    };

    sort(div[0].begin(), div[0].end(), comp1);
    sort(div[1].begin(), div[1].end(), comp2);
    sort(div[2].begin(), div[2].end(), comp3);
    sort(div[3].begin(), div[3].end(), comp4);

    int tot = 2*n;

    for(int i = 0; i < n; i++) {
        if (vp[i].first != 0) tot += 2;
        if (vp[i].second != 0) tot += 2;
    }

    cout << tot << "\n";
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < div[i].size(); j++) {
            int p1 = div[i][j].first;
            int p2 = div[i][j].second;

            if (p1 > 0)  {
                cout << 1 << " " << p1 << " " << "R" << "\n";
            }
            if (p1 < 0) {
                cout << 1 << " " << abs(p1) << " " << "L" << "\n";
            }
            if (p2 > 0) {
                cout << 1 << " " << p2 << " " << "U" << "\n";
            }
            if (p2 < 0) {
                cout << 1 << " " << abs(p2) << " " << "D" << "\n";
            }

            cout << 2 << "\n";

            if (p1 > 0) {
                cout << 1 << " " << p1 << " " << "L" << "\n";
            }
            if (p1 < 0) {
                cout << 1 << " " << abs(p1) << " " << "R" << "\n";
            }
            if (p2 > 0) {
                cout << 1 << " " << p2 << " " << "D" << "\n";
            }
            if (p2 < 0) {
                cout << 1 << " " << abs(p2) << " " << "U" << "\n";
            }

            cout << 3 << "\n";

        }
    }

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}