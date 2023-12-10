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
const int MAX_N = 2e5 + 5;
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

vll t(4 * MAX_N);

void update(ll tIndex, ll val, ll tl, ll tr, ll l, ll r){
    if (l <= tl && r >= tr) {
        t[tIndex] += val; return;
    }
    if (r <= tl || l >= tr) return;
    ll m = (tl + tr) / 2;
    update(2 * tIndex + 1, val, tl, m, l, r);
    update(2 * tIndex + 2, val, m, tr, l, r);
}

ll query(ll index, ll tIndex, ll tl, ll tr){
    ll ans = t[tIndex];
    if (tr - tl == 1) return ans;
    ll m = (tl + tr) / 2;
    if (index < m) ans += query(index, 2 * tIndex + 1, tl, m);
    else ans += query(index, 2 * tIndex + 2, m, tr);
    return ans;
}

void solve(int tt) {
    ll n, q; cin >> n >> q;
    forn(i, n){
        ll x; cin >> x;
        update(0, x, 0, n, i, i+1);
    }
    forn(i, q){
        ll y; cin >> y;
        if (y == 1){
            ll a, b, u; cin >> a >> b >> u;
            update(0, u, 0, n, a-1, b);
        }
        else{
            ll k; cin >> k;
            cout << query(k-1, 0, 0, n) << endl;
        }
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