#include<bits/stdc++.h>
using namespace std;
//defines
#define ll    long long
#define pb    push_back
#define popb  pop_back
#define ff    first
#define ss    second
#define pll   pair<ll,ll>
#define nl    "\n"
#define gcd(a, b) ((b) == 0 ? (a) : gcd((b), (a) % (b)))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1000000007;
const long double pi=3.14159265358979323846264338327950288419716939937510582097494459230;

//functions
void solve();
ll bin_expo(ll a, ll b, ll MOD = mod) {
    ll ans = 1;
    while (b) {
        if (b % 2) ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    } return ans;
}

ll inverse(ll a) {
    return bin_expo(a, mod - 2, mod);
}
void csort(vector <ll>);
void csort(vector <int>);
void csort(vector <ll> &v){
    ll i = 0;
    while(i < v.size()){
        ll cur = v[i] - 1;
        if(cur < v.size() && v[i] != v[cur]){
            swap(v[i],v[cur]);
        }else
            i++;
    }
}
void csort(vector <int> &v){
    ll i = 0;
    while(i < v.size()){
        ll cur = v[i] - 1;
        if(cur < v.size() && v[i] != v[cur]){
            swap(v[i],v[cur]);
        }else
            i++;
    }
}
vector<int> sieve_of_eratosthenes(int limit) {
    std::vector<bool> primes(limit + 1, true);
    primes[0] = primes[1] = false;  // 0 and 1 are not prime
    for (int num = 2; num * num <= limit; ++num) {
        if (primes[num]) {
            for (int multiple = num * num; multiple <= limit; multiple += num) {
                primes[multiple] = false;
            }
        }
    }
    std::vector<int> prime_numbers;
    for (int num = 2; num <= limit; ++num) {
        if (primes[num]) {
            prime_numbers.push_back(num);
        }
    }
    return prime_numbers;
}
ll tc = 0;
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll tt; cin >> tt;
    while(tt--)
        solve();
    return 0;
}
void solve(){
    ll n, k, a, b;
    cin >> n >> k >> a >> b; a--; b--;
    vector<vector<ll>> v(n, vector<ll> (2));
    vector<vector<ll>> major(k, vector<ll>(2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 2; j++) major[i][j] = v[i][j];
    }
    long long int cost = abs(v[a][0] - v[b][0]) + abs(v[a][1] - v[b][1]);
    long long int mincost1 = 1e12;
    long long int mincost2 = 1e12;
//    cout << "here" << "\n";
//    return;
    for (int i = 0; i < k; i++) {
        mincost1 = min(mincost1, abs(v[a][0] - major[i][0]) + abs(v[a][1] - major[i][1]));
    }
    for (int i = 0; i < k; i++) {
        mincost2 = min(mincost2, abs(v[b][0] - major[i][0]) + abs(v[b][1] - major[i][1]));
    }
//    cout << mincost1 << " " << mincost2 << "\n";
    cout << min(cost, mincost1 + mincost2) << "\n";
}