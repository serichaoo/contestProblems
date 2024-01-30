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
const int MAX_N = 2e5 + 10;
const ll MOD = 1e9 + 7; // 998244353
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

vll lfa(MAX_N, -1);

ll binExp(ll a, ll b){
    if (b == 0) return 1;
    if (b == 1) return a;
    return binExp(a*a, b/2) * binExp(a, b%2);
}

vll factors(ll n){
    map<ll, ll> primeFactors;
    while (n != 1){
        primeFactors[lfa[n]]++;
        n /= lfa[n];
    }
    vll ret = {1};
    for (auto x : primeFactors){
        vll newElements;
        ll pow = 1;
        for (ll y : ret)
            for(ll i = 0; i<x.second; i++){
                newElements.pb(pow*x.first * y);
                pow *= x.first;
            }
        for (ll y : newElements)
            ret.pb(y);
    }
    return ret;
}

void solve(int tt) {
    ll n; cin >> n;
    vll a(n);
    forn(i, n)
        cin >> a[i];
    // vll factorsN = factors(n);
    vll factorsN;
    for (ll i = 1; i*i<=n; i++){
        if (n % i == 0){
            factorsN.pb(i);
            if (i*i != n)
                factorsN.pb(n/i);
        }
    }
    ll ans = 0;
    for (ll d : factorsN){
        if (d == n){
            ans++;
            continue;
        }
        ll g = abs(a[0]-a[d]);
        bool stop = 0;
        for (ll i=0; i<n-d; i++){
            g = gcd(g, a[i+d] - a[i]);
            if (g == 1){
                stop = 1;
                break;
            }
        }
        if (!stop)
            ans++;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(20);

    lfa[1] = 1;
    for (ll i=2; i<MAX_N; i++){
        for (ll j=1; i*j<MAX_N; j++)
            if (lfa[i*j] == -1)
                lfa[i*j] = i;
    }

    int t = 1;
    if (multiTest)
        cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        solve(ii);
    }
}