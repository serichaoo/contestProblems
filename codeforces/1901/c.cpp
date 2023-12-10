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

// map<ll, ll> log;
ll lg(ll x){
    ll b = x;
    ll ans = -1;
    while (b){
        b >>= 1;
        ans++;
    }
    return ans;
}

void solve(int tt) {
    ll n;
    cin >> n;
    vll a(n);
    forn(i, n){
        cin >> a[i];
    }
    if (n == 1){
        cout << 0 << endl;
        return;
    }
    sort(all(a));
    if (a[0] == a[n-1]){
        cout << 0 << endl;
        return;
    }
    ll add = 0;
    while (true){
        if (lg(a[0]) == lg(a[n-1])){
            ll diff = (1 << lg(a[0]));
            forn(i, n)
                a[i] -= diff;
            continue;
        }
        else if (lg((((1 << lg(a[n-1])) - a[0]) + a[n-1])) == lg(a[n-1])){
            ll diff = (1 << lg(a[n-1])) - ((1 << lg(a[n-1])) - a[0]);
            add += ((1 << lg(a[n-1])) - a[0]);
            forn(i, n){
               a[i] -= diff;
            }
            continue;
        }
        break;
    }
    ll ans = lg(a[n-1]) + 1;
    cout << ans << endl;
    if (ans > n)
        return;
    cout << add << ' ';
    forn(i, ans-1){
        cout << 0 << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(20);

    // ll pow = 0; ll lg = 1;
    // while (lg < 1e11){
    //     log[lg] = pow;
    //     lg *= 2;
    //     pow++;
    // }
    int t = 1;
    if (multiTest)
        cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        solve(ii);
    }
}