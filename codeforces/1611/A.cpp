#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}


void solve() {
    int n; cin >> n;
    int temp = n; int flg = 0;
    string s = to_string(n);
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] - '0') % 2 == 0) {
            flg = 1;
            break;
        }
    }
    if (!flg) {
        cout << -1 << "\n";
        return;
    } else {
        if ((s[s.length() - 1] - '0') % 2 == 0) cout << 0 << "\n";
        else if ((s[0] - '0') % 2 == 0) cout << 1 << "\n";
        else cout << 2 << "\n";
    }

}