#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimization("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fi first
#define se second

using ld = long double;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const ld EPS = 1e-9;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

bool multiTest = 1;

vll phi(1e5 + 1);

void solve(int tt) {
    ll n; cin >> n;
    vll a(n);
    forn(i, n){
        cin >> a[i];
    }
    sort(all(a));
    vll divisorCount(1e5+1);
    vector<vll> divisorCountIndices(1e5+1);
    forn(i, n){
        for (ll j = 1; j*j<= a[i]; j++){
            if (a[i] % j == 0){
                divisorCount[j]++;
                divisorCountIndices[j].pb(i);
                if (j * j != a[j]){
                    divisorCount[a[i]/j]++;
                    divisorCountIndices[a[i]/j].pb(i);
                }
            }
        }
    }
    ll ans = 0;
    forn(i, a[n-1]+1){
        ans += (n-1) * phi[i] * (divisorCount[i] * (divisorCount[i]-1))/2;
    }
    forn(i, a[n-1]+1){
        if (divisorCountIndices[i].size() > 1){
            forn(j, divisorCountIndices[i].size()){
                ans -= j * (divisorCountIndices[i][j]) * phi[i];
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(20);

    for (ll i = 0; i <= 1e5; i++)
        phi[i] = i;
    for (ll i = 2; i <= 1e5; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= 1e5; j += i)
                phi[j] -= phi[j] / i;
        }
    }

    int t = 1;
    if (multiTest)
        cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        solve(ii);
    }
}