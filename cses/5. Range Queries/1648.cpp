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
ll n;

ll sum(ll v, ll tl, ll tr, ll l, ll r){
    if (r <= tl) return 0;
    if (l >= tr) return 0;
    if (tl >= l && tr <= r) return t[v];
    ll m = (tl + tr) / 2;
    ll s1 = sum(2 * v + 1, tl, m, l, r);
    ll s2 = sum(2 * v + 2, m, tr, l, r);
    return s1 + s2;
}
ll sum(ll a, ll b){
    return sum(0, 0, n, a, b+1);
}

void update(ll index, ll val, ll tIndex, ll tl, ll tr){
    if (tr - tl == 1) {
        t[tIndex] = val;
        return;
    }
    ll m = (tl + tr) / 2;
    if (index < m){
        update(index, val, 2*tIndex + 1, tl, m);
    }
    else{
        update(index, val, 2*tIndex + 2, m, tr);
    }
    t[tIndex] = t[2*tIndex + 1] + t[2 * tIndex + 2];
}

void update(ll index, ll val){
    update(index, val, 0, 0, n);
}


void solve(int tt) {
    ll q;
    cin >> n >> q;
    forn(i, n){
        ll a; cin >> a;
        update(i, a, 0, 0, n);
    }
    forn(i, q){
        ll k; cin >> k;
        if (k == 1){
            ll k, u; cin >> k >> u;
            update(k-1, u);
        }
        else{
            ll a, b;
            cin >> a >> b;
            cout << sum(a-1, b-1) << endl;
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