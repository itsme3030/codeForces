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
   string s;
   cin >> s;
   int n = s.length();
   string t = "twone";
   vector<int> tmp;
   for(int i = 0; i < n-4; i++) {
      string newone = s.substr(i,5);
      if (newone == t) {
         int ind = i+2;
         tmp.push_back(ind + 1);
         s[ind] = 'x';
      }
   }  

   // int pref[n] = {0};
   // pref[0] = 1;
   // for(int i = 1; i < n; i++) {
   //    if(s[i] == s[i-1]) pref[i] = pref[i-1] + 1;
   //    else pref[i] = 1;
   // }
   // int suff[n] = {0};
   // suff[n-1] = 0;
   // for(int i = n-2; i >= 0; i--) {
   //    if(s[i] == s[i+1]) suff[i] = suff[i+1] + 1;
   //    else suff[i] = 1;
   // }
   for(int i = 0; i < n-2; i++) {
      string curr = s.substr(i,3);
      if (curr == "one" || curr == "two") {
         tmp.push_back(i+2);  
      }
   }

   cout << tmp.size() << "\n";
   for(auto &x : tmp) {
      cout << x << " ";
   } cout << "\n";

   // deque<pair<char, int>> dq;
   // int sm = 0;
   // int mx = 1e9;
   // for(int i = 0; i < n; i++) {
   //    if(dq.empty()) {
   //       dq.push_back({s[i], 1});
   //    }else {
   //       pair<char, int> last = dq.back();
   //       if (last.first == s[i]) {
   //          dq.pop_back();
   //          dq.push_back({last.first, last.second + 1});
   //       }else {
   //          dq.push_back({s[i], 1});
   //       }
   //    }

   //    if (dq.size() >= 4) {
   //       sm += mx;
   //       int psm = 0;
   //       if(dq[2].second == mx) {
   //          for()
   //       }
   //       mx = 1e9;
   //       dq.pop_front();
   //    }
   //    if(dq.size() == 3) {
   //       int ff = dq[0].second;
   //       int ss = dq[1].second;
   //       int tt = dq[2].second;
   //       string s;
   //       s += dq[0].first;
   //       s += dq[1].first;
   //       s += dq[2].first;
   //       if(s == "one" || s == "two") {
   //          mx = min(mx, min({ff, ss, tt}));
   //       }
   //    }
   // }
   // if(mx != 1e9) sm += mx;
   // cout << sm << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}