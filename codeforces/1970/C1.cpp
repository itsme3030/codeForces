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
  int n,t;
  cin >> n >> t;
  vector<vector<int>> g(n);
  for(int i = 0; i < n-1; i++) {
   int x,y;
   cin >> x >> y;
   x--, y--;
   g[x].push_back(y);
   g[y].push_back(x);
  } 
  int tar;
  cin >> tar;
  
  queue<int> q;
  q.push(--tar);
  vector<int> vis(n, 0);
  vector<int> dis(n, 0);
  dis[tar]=0;
  vis[tar]++;

  vector<int> temp;
  while (!q.empty()) {
      int top = q.front();
      q.pop();

      if (g[top].size() == 1) temp.push_back(dis[top]); 

      for (auto &child : g[top]) {
         if (!vis[child]) {
            vis[child] = 1;
            dis[child] = dis[top] + 1;
            q.push(child);
         }
      }

  }

  
  int isOdd = temp[0]%2;
  if (temp.size()>1) isOdd = isOdd | temp[1]%2;
  if (isOdd) {
   cout << "Ron\n";
  } else {
   cout << "Hermione\n";
  }

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}