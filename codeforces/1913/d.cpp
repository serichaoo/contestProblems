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
const int MAX_N = 1e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-9;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

vi d4x = {1, 0, -1, 0};
vi d4y = {0, 1, 0, -1};
vi d8x = {1, 0, -1, 0, 1, 1, -1, -1};
vi d8y = {0, 1, 0, -1, 1, -1, 1, -1};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

bool multiTest = 1;

vll t;
vll p;
vll invP;

void build(vll &a, ll x, ll tl, ll tr){
    if (tr - tl == 1){
        t[x] = a[tl];
        return;
    }
    ll m = (tl + tr)/2;
    build(a, 2*x+1, tl, m);
    build(a, 2*x+2, m, tr);
    t[x] = min(t[2*x+1], t[2*x+2]);
}

ll query(ll l, ll r, ll x, ll tl, ll tr){
    if (tl >= l && tr <= r) return t[x];
    if (tl >= r || tr <= l) return INF;
    ll m = (tl + tr)/2;
    return min(query(l, r, 2*x+1, tl, m), query(l, r, 2*x+2, m, tr));
}

ll query(ll l, ll r){
    return invP[query(l, r, 0, 0, p.size())];
}

ll bothMin(ll l, ll r){
    if (r - l == 0) return 1;
    if (r - l == 1) return 2;
    ll minIndex = query(l, r);
    return ((bothMin(l, minIndex)+1)%MOD) * ((bothMin(minIndex+1, r) + 1) % MOD) % MOD;
}

ll lMin(ll l, ll r){
    if (r - l == 1) return 2;
    if (r - l == 0) return 1;
    ll minIndex = query(l, r);
    return (((bothMin(l, minIndex)+1)%MOD) * lMin(minIndex+1, r))%MOD;
}

ll rMin(ll l, ll r){
    if (r - l == 1) return 2;
    if (r - l == 0) return 1;
    ll minIndex = query(l, r);
    return (((rMin(l, minIndex))%MOD) * ((bothMin(minIndex+1, r))+1))%MOD;
}

void solve(int tt) {
    ll n; cin >> n;
    p.resize(n);
    t.resize(4 * n + 20);
    vll a(n);
    vll b(n);
    forn(i, n){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(all(a));
    map<ll, ll> compress;
    for (auto x : a){
        compress[x] = lower_bound(all(a), x) - a.begin();
    }
    forn(i, n){
        p[i] = compress[b[i]];
    }
    invP.resize(n);
    forn(i, n){
        invP[p[i]] = i;
    }
    build(p, 0, 0, n);
    ll minIndex = query(0, n);
    cout << (rMin(0, minIndex) * lMin(minIndex+1, n)) % MOD << endl;
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    // cout.precision(20);

    int t = 1;
    if (multiTest)
        cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        solve(ii);
    }
}