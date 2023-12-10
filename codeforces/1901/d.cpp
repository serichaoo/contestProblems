#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define fi first
#define se second

using ld = long double;
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

bool multiTest = 0;

vll a;
ll n;
ll maxVal = 0;
bool isValid(ll power){
    ll l = 0; ll r = n-1;
    if (power > maxVal + n) return 1;
    forn(i, n){
        if (power < a[i]) return 0;
        if (power - i < a[i]) l = i;
        if (l > r) return 0;
    }
    for (ll i = n-1; i>= 0; i--){
        if (power - (n - i - 1) < a[i]) r = i;
        if (l > r) return 0;
    }
    return 1;
}

void solve(int tt) {
    cin >> n;
    a = vll(n);
    forn(i, n){
        cin >> a[i];
    }
    forn(i, n)
        maxVal = max(maxVal, a[i]);
    ll l = 0; ll r = 1e10;
    while (l < r){
        if (r - l == ll(1)){
            cout << r; return;
        }
        ll m = (l + r)/2;
        if (isValid(m)){
            r = m;
        }
        else l = m;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(20);

    int t = 1;
    if (multiTest)
        cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        solve(ii);
    }
}