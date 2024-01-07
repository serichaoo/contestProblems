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

void solve(int tt) {
    ll n, k; cin >> n >> k;
    ll minV = 1e13;
    ll maxV = 0;
    vll a(n);
    forn(i, n){
        cin >> a[i];
        minV = min(minV, a[i]);
        maxV = max(maxV, a[i]);
    }
    if (minV == maxV){
        cout << 0 << endl;
        return;
    }
    if (minV <= k && maxV >= k){
        cout << -1 << endl;
        return;
    }
    ll ans = 0;
    if (maxV < k){
        forn(i, n){
            a[i] = 2* k - a[i];
        }
        minV = 2 * k - minV;
        maxV = 2 * k - maxV;
    }
    // if (minV > k){
    ll g = abs(a[1] - a[0]);
    for (int i=2; i<n; i++){
        g = gcd(g, abs(a[i] - a[i-1]));
    }
    if (k + g > minV){
        ll x = minV - k;
        for (ll i = min(g, x); i >= 0; i--){
            if (g % i == 0){
                g = i;
                break;
            }
        }
        //g = gcd(g, abs(minV - k));
    }
    forn(i, n){
        ans += (abs(a[i] - k - g))/g;
    }
    // }
    // else{
    //     ll g = abs(a[1] - a[0]);
    //     for (int i=2; i<n; i++){
    //         g = gcd(g, abs(a[i] - a[i-1]));
    //     }
    //     ll x = k - g;
    //     if (x < maxV){
    //         g = gcd(g, abs(maxV - k));
    //     }
    //     x = k-g;
    //     forn(i, n){
    //         ans += (x - a[i])/g;
    //     }
    // }
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