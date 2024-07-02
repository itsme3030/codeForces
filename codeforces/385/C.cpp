#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
bool bprime[10000001];
int iprime[10000001];
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    for(int i = 2; i <= 10000000; i++) {
        if (!bprime[i]) {
            iprime[i] = i;
            for(int j = i*2; j <= 10000000; j += i) {
                bprime[j] = true;
                if (iprime[j] == 0) iprime[j] = i;
            }
        }
    }

    map<int, int> freq;
    for(int i = 0; i < n; i++) {
        int ele = v[i];

        while (ele > 1) {
            int fct = iprime[ele];
            freq[fct]++;
            while(ele % fct == 0) {
                ele/=fct;
            }
        }

//        for(int j = 0; iprime[j]*iprime[j] <= ele; j++) {
//            if (ele % iprime[j] == 0) {
//                while (ele % iprime[j] == 0) {
//                    ele/=iprime[j];
//                }
//                freq[iprime[j]]++;
//            }
//        }
//        if (ele > 1) {
//            freq[ele]++;
//        }
    }


    vector<pair<int, int>> vp(freq.begin(), freq.end());
    vector<pair<int, int>> pref(vp.size() + 1);

    pref[0].first = 0, pref[0].second = 0;
    for(int i = 1; i < pref.size(); i++) {
        pref[i].first = vp[i-1].first;
        pref[i].second = pref[i-1].second;
        pref[i].second += vp[i-1].second;
    }

    int m;
    cin >> m;


    while (m--) {
        int l,r;
        cin >> l >> r;
        //find l and r in pref array
        //l as lower_bound and do -1
        //r as upper_bound and do -1;
        int indl = lower_bound(pref.begin(), pref.end(), make_pair(l, 0LL)) - pref.begin() - 1;
        int indu = upper_bound(pref.begin(), pref.end(), make_pair(r, inf)) - pref.begin() - 1;

//        int indl = 0; int indu = pref.size() - 1;
//        int lo = 0, hi = pref.size()-1;
//        while (lo <= hi) {
//            int mid = (lo + hi) >> 1;
//            if (pref[mid].first < l) {
//                indl = mid;
//                lo = mid + 1;
//            } else {
//                hi = mid - 1;
//            }
//        }


//        lo = 0, hi = pref.size()-1;
//        while (lo <= hi) {
//            int mid = (lo + hi) >> 1;
//            if (pref[mid].first <= r) {
//                indu = mid;
//                lo = mid + 1;
//            } else {
//                hi = mid - 1;
//            }
//        }

        cout << pref[indu].second - pref[indl].second << "\n";
    }

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}