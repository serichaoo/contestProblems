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
const ll INF = 1e9+5;
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
    // 4 cases:
    // ai bi aj bj
    // bi ai bj aj
    // ai bi bj aj
    // bi ai aj bj
    ll n;
    cin >> n;
    vll a(n), b(n);
    forn(i, n)
        cin >> a[i];
    forn(i, n)
        cin >> b[i];
    ll ans = 0;
    // case 1: ai bi aj bj, take minimal bi, then take maximum aj
    ll minB = INF;
    ll minBIndex = -1;
    forn(i, n){
        if (a[i] <= b[i])
            if (b[i] < minB){
                minB = b[i];
                minBIndex = i;
            }
    }
    ll maxA;
    if (minBIndex != -1){
        maxA=0;
        ll maxAIndex = -1;
        forn(i, n){
            if (a[i] <= b[i]){
                if (a[i] > maxA){
                    maxA = a[i];
                    maxAIndex = i;
                }
            }
        }
        ans = max(ans, max(2*(maxA - minB), ll(0)));
    }
    // case 2: same as case 1 but switch A and B bi ai bj aj
    ll minA = INF;
    ll minAIndex = -1;
    forn(i, n){
        if (a[i] >= b[i])
            if (a[i] < minA){
                minA = a[i];
                minAIndex = i;
            }
    }
    ll maxB;
    if (minAIndex != -1){
        maxB=0;
        ll maxBIndex = -1;
        forn(i, n){
            if (a[i] >= b[i]){
                if (b[i] > maxB){
                    maxB = b[i];
                    maxBIndex = i;
                }
            }
        }
        ans = max(ans, max(2*(maxB - minA), ll(0)));
    }
    // case 3: ai bi bj aj, find min bi and max bj
    // case 4: bi ai aj bj, find min ai and max aj
    minB = INF;
    maxB = 0;
    // ll minBIndex = -1;
    // ll maxBIndex = -1;
    minA = INF;
    maxA = 0;
    // ll minAIndex = -1;
    // ll maxAIndex = -1;
    forn(i, n){
        if (a[i] <= b[i]){
            maxA = max(maxA, a[i]);
            minB = min(minB, b[i]);
        }
        if (a[i] >= b[i]){
            minA = min(minA, a[i]);
            maxB = max(maxB, b[i]);
        }
        ans = max(ans, 2*(max(maxB - minB, ll(0))));
        ans = max(ans, 2*(max(maxA - minA, ll(0))));
    }
    forn(i, n)
        ans += abs(a[i] - b[i]);
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