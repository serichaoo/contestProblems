#include <bits/stdc++.h>
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

// map<pll, pll> vals;

pll minOps(ll a, ll b){
    // if (a <= b) return make_pair(0, a);
    // if (vals.find(make_pair(a, b)) != vals.end()) return vals[make_pair(a, b)];
    // pll x = minOps(a/2, b);
    // pll y = minOps((a+1)/2, b);
    // pll z = make_pair(x.fi + y.fi + 1, min(x.se, y.se));
    // vals[make_pair(a, b)] = z;
    // return z;
    if (a <= b) return make_pair(0, a);
    return make_pair((a-1)/b, a/(((a-1)/b)+1));
}

void solve(int tt) {
    ll n;
    cin >> n;
    vll a(n);
    forn(i, n)
        cin >> a[i];
    reverse(all(a));
    ll ans = 0;
    ll preVal = a[0];
    for (int i = 1; i<n; i++){
        pll b = minOps(a[i], preVal);
        ans += b.fi;
        preVal = b.se;
    }
    cout << ans << endl;
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