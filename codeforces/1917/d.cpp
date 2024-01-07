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
const int MAX_N = 4e5 + 5;
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

vll t(4 * MAX_N);

ll n;

// void build(vll &p, ll v, ll tl, ll tr){
//     if (tr - tl == 1){
//         t[v] = p[tl];
//         return;
//     }
//     ll m = (tl + tr)/2;
//     build(p, 2*v+1, tl, m);
//     build(p, 2*v+2, m, tr);
//     t[v] = t[2*v+1] + t[2*v+2];
// }

void update(ll i, ll v, ll x, ll tl, ll tr){
    if (tr - tl == 1){
        t[x] = v;
        return;
    }
    ll m = (tl + tr)/2;
    if (i < m)
        update(i, v, 2*x+1, tl, m);
    else
        update(i, v, 2*x+2, m, tr);
    t[x] = t[2*x+1] + t[2*x+2];
}

void update(ll i){
    update(i, 1, 0, 0, 2*n);
}

ll query(ll l, ll r, ll x, ll tl, ll tr){
    if (tl >= l && tr <= r) return t[x];
    if (tr <= l || tl >= r) return 0;
    ll m = (tl + tr)/2;
    return query(l, r, 2*x+1, tl, m) + query(l, r, 2*x+2, m, tr);
}

ll query(ll l, ll r){
    return query(l, r, 0, 0, 2*n);
}

void solve(int tt) {
    ll k; cin >> n >> k;
    forn(i, 4 * (2 * n + 5)){
        t[i] = 0;
    }
    vll p(n), q(k);
    forn(i, n)
        cin >> p[i];
    forn(i, k)
        cin >> q[i];
    ll ans = 0;
    // finding num inversion within same element in p
    ordered_multiset s;
    ll t = 0;
    forn(i, k){
        ans += i - s.order_of_key({q[i]+1, 0});
        ans %= MOD;
        s.insert({q[i], t++});
    }
    ans *= n;
    ans %= MOD;

    // finding num inversion across different elements p
    // process from right to left for simplicity
    for (int i=n-1; i>=0; i--){
        ll l = p[i];
        ll r = 2*p[i];
        ll m = 1;
        while (l < 2*n && m < k){
            ll cnt = query(l, r);
            ans += cnt * (k-m)*(k-m+1)/2;
            ans %= MOD;
            m++;
            l *= 2;
            r *= 2;
        }
        l = p[i]/2 + 1;
        r = p[i]+1;
        m = 0;
        while (l < r && m + k > 0){
            ll cnt = query(l, r);
            ans += cnt * (k+m)*(k+m+1)/2;
            ans %= MOD;
            m--;
            l = (p[i] >> (- m)) + 1;
            r = (p[i] >> (1 - m))+1;
        }
        update(p[i]);
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