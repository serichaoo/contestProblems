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

vi d4x = {1, 0, -1, 0};
vi d4y = {0, 1, 0, -1};
vi d8x = {1, 0, -1, 0, 1, 1, -1, -1};
vi d8y = {0, 1, 0, -1, 1, -1, 1, -1};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

bool multiTest = 1;

ll binExp(ll base, ll pow){
    base %= MOD;
    if (pow == 0) return 1;
    if (pow == 1) return base;
    return (binExp(base*base, pow/2) * binExp(base, pow%2)) % MOD;
}

vll fact(MAX_N);
vll invFact(MAX_N);

ll binCoeff(ll n, ll m){ // n C m
    return (((fact[n] * invFact[m]) % MOD) * invFact[n - m]) % MOD;
}

ll inverse(ll n){
    return binExp(n, MOD-2);
}

void solve(int tt) {
    ll n, m, k; cin >> n >> m >> k;
    vll f(m);
    ll sumF = 0;
    forn(i, m){
        ll a, b, fI; cin >> a >> b >> fI;
        f.pb(fI);
        sumF += fI;
        sumF %= MOD;
    }
    // p = 1/(nC2)
    ll p = inverse(binCoeff(n, 2));
    ll notP = ((binCoeff(n, 2) - 1) * inverse(binCoeff(n, 2))) % MOD;

    ll ans = 0;
    vll pExp(k+1), notPExp(k+1);
    pExp[0] = notPExp[0] = 1;
    for (int i=0; i<k; i++){
        pExp[i+1] = (pExp[i] * p) % MOD;
        notPExp[i+1] = (notPExp[i] * notP) % MOD;
    }
    
    for (ll i=0; i<=k; i++){
        // (pExp[i] * notPExp[k-i] * binCoeff(k, i) * i) * (i * sumF + m * i * (i - 1) / 2)
        ll addend = (((pExp[i] * notPExp[k-i]) % MOD) * binCoeff(k, i)) % MOD;
        addend *= (((i * sumF) % MOD) + (((((m * i) % MOD) * (i-1)) % MOD) * inverse(2)) % MOD) % MOD;
        addend %= MOD;
        ans += addend;
        ans %= MOD;
    }

    // ll a = 0;
    // for (ll i=0; i<=k; i++){
    //     // (pExp[i] * notPExp[k-i] * binCoeff(k, i) * i) * (i * sumF + m * i * (i - 1) / 2)
    //     ll addend = (((((pExp[i] * notPExp[k-i]) % MOD) * binCoeff(k, i)) % MOD) * i) % MOD;
    //     addend %= MOD;
    //     a += addend;
    //     a %= MOD;
    // }
    // a *= sumF;
    // a %= MOD;

    // ll b = 0;
    // for (ll i=0; i<=k; i++){
    //     // (pExp[i] * notPExp[k-i] * binCoeff(k, i) * i) * (i * sumF + m * i * (i - 1) / 2)
    //     ll addend = (((pExp[i] * notPExp[k-i]) % MOD) * binCoeff(k, i)) % MOD;
    //     addend *= (((i * (i - 1)) % MOD) * inverse(2)) % MOD;
    //     addend %= MOD;
    //     b += addend;
    //     b %= MOD;
    // }
    // b *= m;
    // cout << (a + b) % MOD << endl;

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(20);
    fact[0] = 1;
    for (int i=1; i<MAX_N; i++){
        fact[i] = fact[i-1] * i;
        fact[i] %= MOD;
    }
    invFact[MAX_N - 1] = binExp(fact[MAX_N - 1], MOD-2);
    for (int i=MAX_N-1; i>= 1; i--){
        invFact[i - 1] = invFact[i] * i;
        invFact[i-1] %= MOD;
    }
    int t = 1;
    if (multiTest)
        cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        solve(ii);
    }
}