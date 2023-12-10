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

vll t(4 * MAX_N);
ll n;

void update(ll x, ll l, ll r, ll tl, ll tr){
    if (tl >= l && tr <= r){
        t[x]++;
        return;
    }
    if (tl >= r || tr <= l) return;
    ll m = (tl + tr)/2;
    update(2*x+1, l, r, tl, m);
    update(2*x+2, l, r, m, tr);
}

void update(ll index){
    update(0, index, n, 0, n);
}

ll query(ll i, ll x, ll tl, ll tr){
    ll ans = t[x];
    if (tr - tl == 1) return ans;
    ll m = (tl + tr)/2;
    if (i < m) ans += query(i, 2*x+1, tl, m);
    else ans += query(i, 2*x+2, m, tr);
    return ans;
}

ll query(ll index){
    return query(index, 0, 0, n);
}

void solve(int tt) {
    cin >> n;
    vll x(n);
    forn(i, n) cin >> x[i];
    forn(i, n){
        ll a; cin >> a;
        a--;
        ll q = a + query(a);
        cout << x[q] << ' ';
        update(a);
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