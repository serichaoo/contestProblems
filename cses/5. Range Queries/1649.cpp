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

vll t(4 * MAX_N, INF);

ll n;

ll rangeMin(ll tIndex, ll tl, ll tr, ll l, ll r){
    if (l >= tr || r <= tl) return INF;
    if (l <= tl && r >= tr) return t[tIndex];
    ll m = (tl + tr) / 2;
    ll min1 = rangeMin(2 * tIndex + 1, tl, m, l, r);
    ll min2 = rangeMin(2 * tIndex + 2, m, tr, l, r);
    return min(min1, min2);
}
ll rangeMin(ll a, ll b){
    return rangeMin(0, 0, n, a, b);
}

void update(ll index, ll val, ll tIndex, ll tl, ll tr){
    if (tr - tl == 1) {
        t[tIndex] = val;
        return;
    }
    ll m = (tl + tr) / 2;
    if (index < m)
        update(index, val, 2 * tIndex + 1, tl, m);
    else
        update(index, val, 2 * tIndex + 2, m, tr);
    t[tIndex] = min(t[2*tIndex+1], t[2*tIndex+2]);
}
void update(ll index, ll val){
    update(index, val, 0, 0, n);
}

void solve(int tt) {
    cin >> n;
    ll q; cin >> q;
    forn(i, n){
        ll x; cin >> x;
        update(i, x);
    }
    forn(i, q){
        ll y; cin >> y;
        if (y == 1){
            ll k, u; cin >> k >> u;
            update(k-1, u);
        }
        else{
            ll a, b; cin >> a >> b;
            cout << rangeMin(a-1, b) << endl;
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