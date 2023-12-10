#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fi first
#define se second
#define endl '\n'

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

vll t(4*MAX_N);

void build(vll &a, ll x, ll tl, ll tr){
    if (tr - tl == 1){
        t[x] = a[tl];
        return;
    }
    ll m = (tl + tr)/2;
    build(a, 2*x+1, tl, m);
    build(a, 2*x+2, m, tr);
    t[x] = max(t[2*x+1], t[2*x+2]);
}

ll query(ll v, ll x, ll tl, ll tr){
    if (t[x] < v)  
        return INF;
    if (tr - tl == 1)
        return tl;
    ll m = (tl + tr)/2;
    if (t[2*x+1] >= v) return query(v, 2*x+1, tl, m);
    else return query(v, 2*x+2, m, tr);
    // ll q1 = query(v, 2*x+1, tl, m);
    // if (q1 != INF) return q1;
    // return query(v, 2*x+2, m, tr);
}

void update(ll k, ll v, ll x, ll tl, ll tr){ // reduces element k by v
    if (tr - tl == 1){
        t[x] -= v;
        return;
    }
    ll m = (tl + tr)/2;
    if (k < m) update(k, v, 2*x+1, tl, m);
    else update(k, v, 2*x+2, m, tr);
    t[x] = max(t[2*x+1], t[2*x+2]);
}



void solve(int tt) {
    ll n, m; cin >> n >> m;
    vll h(n);
    forn(i, n) cin >> h[i];
    // ll n = 2e5, m = 2e5;
    // vll h(n, 1);
    build(h, 0, 0, n);
    forn(i, m){
        ll r; cin >> r;
        // ll r = 1;
        ll q = query(r, 0, 0, n);
        if (q == INF) q=-1;
        cout << q+1 << ' ';
        if (q != -1){
            update(q, r, 0, 0, n);
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