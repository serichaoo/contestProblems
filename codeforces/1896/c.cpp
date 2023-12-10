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

void solve(int tt) {
// find min and max value
    ll n, x; cin >> n >> x;
    vll a(n), b(n);
    forn(i, n)
        cin >> a[i];
    forn(i, n)
        cin >> b[i];
    sort(all(b));
    vector<pll> c(n);
    forn(i, n){
        c[i] = {a[i], i};
    }
    sort(all(c));
    vll ans(n);
    forn(i, x){
        if (!(b[i] < c[n-x+i].fi)){
            cout << "NO" << endl;
            return;
        }
        ans[c[n-x+i].se] = b[i];
    }
    forn(i, n-x){
        if (b[x + i] < c[i].fi){
            cout << "NO" << endl;
            return;
        }
        ans[c[i].se] = b[x+i];
    }
    cout << "YES" << endl;
    forn(i, n){
        cout << ans[i] << ' ';
    }
    cout << endl;
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