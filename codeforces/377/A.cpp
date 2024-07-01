#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};
void dfs(vector<vector<char>> &v, int &tmp, int i, int j, vector<vector<int>> &vis) {
    if (tmp == 0) return;
    vis[i][j] = 1;

    for(int k = 0; k < 4; k++) {
        int nr = row[k] + i;
        int nc = col[k] + j;
        if (nr >= 0 && nr < v.size() && nc >= 0 && nc < v[0].size() && vis[nr][nc] == 0 && v[nr][nc] == '.') {
            dfs(v, tmp, nr, nc, vis);
        }
    }


    bool isPath = false;
    for(int k = 0; k < 4; k++) {
        int nr = row[k] + i;
        int nc = col[k] + j;
        if (nr >= 0 && nr < v.size() && nc >= 0 && nc < v[0].size() && vis[nr][nc] == 0 && v[nr][nc] == '.') {
            isPath = true;
            break;
        }
    }
    if (!isPath && tmp > 0) {
        v[i][j] = 'X';
        tmp--;
    }
}

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<char>> v(n, vector<char> (m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    int tmp = k;
    vector<vector<int>> vis(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (v[i][j] == '.' && vis[i][j] == 0) {
                dfs(v, tmp, i,j, vis);
            }
        }
    }

    for(auto &x : v) {
        for(auto &y : x) {
            cout << y;
        } cout << "\n";
    } cout << "\n";
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}