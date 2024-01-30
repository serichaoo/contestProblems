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
    // vector<bool> isCycleLength(MAX_N, 0);
    // vector<bool> isVal(MAX_N, 0);
    vll cycleLengths;
    map<ll, ll> val;
    ll length = 0;
    ll n, q; cin >> n >> q;
    bool stop = 0;
    forn(i, n){
        ll b, x; cin >> b >> x;
        if (stop)
            continue;
        if (b == 1){
            length++;
            // isVal[length] = 1;
            val[length] = x;
        }
        else{
            // isCycleLength[length] = 1;
            cycleLengths.pb(length);
            if (length > 1e18 / (x+1) + 1)
                stop = 1;
            length *= (x+1);
        }
    }
    forn(i, q){
        ll k; cin >> k;
            while (true){
            if (val.count(k)){
                cout << val[k] << " ";
                break;
            }
            else{
                ll mod = *(--lower_bound(all(cycleLengths), k));
                k = (k-1)%mod + 1;
            }
        }
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