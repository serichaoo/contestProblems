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

ll charMap(char a){
    if (a == 'U') return 0;
    if (a == 'L') return 1;
    if (a == 'R') return 2;
    return -1;
}

vector<pll> children;
// vll parent;
vll direction;
vector<bool> leafNodes;

ll dp(ll node){
    if (node == -1) return INF;
    if (leafNodes[node]) return 0;
    if (direction[node] == 0){
        return 1 + min(dp(children[node].fi), dp(children[node].se));
    }
    if (direction[node] == 1){
        return min(dp(children[node].fi), dp(children[node].se) + 1);
    }
    if (direction[node] == 2){
        return min(dp(children[node].fi) + 1, dp(children[node].se));
    }
}

void solve(int tt) {
    // must change all non-leaf U's on the path to L's or R's
    children.clear();
    // parent.clear();
    direction.clear();
    leafNodes.clear();
    ll n; cin >> n;
    str s; cin >> s;
    forn(i, n)
        direction.pb(charMap(s[i]));
    forn(i, n){
        ll a, b;
        cin >> a >> b;
        if (a || b)
            leafNodes.push_back(0);
        else
            leafNodes.push_back(1);
        a--; b--;
        children.push_back({a, b});
    }
    cout << dp(0) << endl;
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