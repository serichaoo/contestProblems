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

bool multiTest = 0;

void solve(int tt) {
    ll n, q;
    cin >> n >> q;
    vll x(n);
    forn(i, n)
        cin >> x[i];
    vector<vll> rangeMin(n);
    vll log(n+1);
    log[1] = 0;
    for (int i=2; i<=n; i++)
        log[i] = log[i/2] + 1;
    forn(i, n)
        rangeMin[i].push_back(x[i]);
    for (int i=0; i<log[n]; i++){
        for (int j=0; j+(1 << (i+1)) < n+1; j++)
            rangeMin[j].push_back(min(rangeMin[j][i], rangeMin[j+(1 << i)][i]));
    }
    forn(i, q){
        ll a, b; cin >> a >> b;
        a--; b--;
        if (a == b) {
            cout << rangeMin[a][0] << endl;
            continue;}
        ll lg = log[b-a+1];
        cout << min(rangeMin[a][lg], rangeMin[b+1-(1 << lg)][lg]) << endl;
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