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
    ll n; cin >> n;
    vll p(n);
    forn(i, n)
        cin >> p[i];
    vll change(n);
    forn(i, n-1){
        change[i+1]=n-1 - p[i];
    }
    ll minDecrease = INF;
    ll curVelocity = 0;
    ll curDecrement = 0;
    forn(i, n){
        if (p[i] < i){
            ll x = i - p[i];
            curDecrement += x*(x+1)/2;
            curVelocity += x;
        }
    }
    minDecrease = curDecrement;
    for (int i=1; i<n; i++){
        curVelocity += p[i - 1];
        curDecrement -= curVelocity;
        curVelocity -= shiftDecrement[i];
        minDecrease = min(minDecrease, curDecrement);
    }
    cout << n * (n+1)/2 - minDecrease << endl;
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