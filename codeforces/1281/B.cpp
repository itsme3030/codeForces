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
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    map<char, int> fq;
    for(auto &x : s) {
        fq[x]++;
    }
    // fq['Z']++;
    if (s < t) {
        cout << s << "\n";
        return;
    }

    for(int i = 0; i < n-1;i++) {
        fq[s[i]]--;
        if (fq[s[i]] == 0) {
            fq.erase(s[i]);
        }
        // cout << (*fq.begin()).first << "\n";
        if (s[i] > (*fq.begin()).first) {
            for(int j = n-1; j >= 0; j--) {
                if (s[j] == (*fq.begin()).first) {
                    swap(s[i], s[j]);
                    break;
                }
            }
            break;
        }
    }

    if(s < t) {
        cout << s << "\n";
    } else {
        cout << "---" << "\n";
    }





    // int ind = -1;
    // char changedwith = '0';
    // for(int i = 0; i < min(n, m); i++) {
    //     fq[s[i]]--;
    //     if (fq[s[i]] == 0) {
    //         fq.erase(s[i]);
    //     }


    //     if ((s[i] - 'A') >= (t[i] - 'A')) {

    //         if (s[i] - 'A' > t[i] - 'A') {
    //             if ((t[i] - 'A') > ((*fq.begin()).first - 'A')) {
    //                 changedwith = (*fq.begin()).first;
    //                 ind = i;
    //                 break;
    //             } else if ((t[i] - 'A') == ((*fq.begin()).first - 'A')) {
    //                 changedwith = (*fq.begin()).first;
    //                 ind = i;
    //                 break;
    //             }
    //         } else {
    //             if ((t[i] - 'A') > ((*fq.begin()).first - 'A')) {
    //                 changedwith = (*fq.begin()).first;
    //                 ind = i;
    //                 break;
    //             }
    //         }


    //         // if ((t[i] - 'A') > ((*fq.begin()).first - 'A')) {
    //         //     changedwith = (*fq.begin()).first;
    //         //     ind = i;
    //         //     break;
    //         // }else {
    //         //     if((t[i] - 'A') == ((*fq.begin()).first - 'A')){

    //         //     }
    //         //     else{
    //         //         cout << "---" << "\n";
    //         //         return;
    //         //     }
    //         // }
    //     }
    // }
    // if (ind == -1 && changedwith == '0') {
    //     cout << "---" << "\n";
    //     return;
    // }

    // for(int i = ind + 1; i < n; i++) {
    //     if (s[i] == changedwith) {
    //         swap(s[ind], s[i]);
    //         break;
    //     }
    // }
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}