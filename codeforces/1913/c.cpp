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

bool multiTest = 0;
vi vals(30);
void query(){
    ll v; cin >> v;
    vll subtract(30);
    while (v>1){
        ll msb = 31 - __builtin_clz(v);
        ll vDiff = v - (1 << msb);
        bool pl = true;
        for (ll i = msb; i >= 0; i--){
            if (vDiff < (vals[i] - subtract[i]) * (1 << i)){
                ll n = vDiff / ((1 << i))+1;
                subtract[i] += n;
                vDiff -= n * (1 << i);
                pl = 0;
                break;
            }
            else{
                ll n = vals[i] - subtract[i];
                subtract[i] += n;
                vDiff -= n * (1 << i);
            }
        }
        if (pl){
            cout << "NO" << endl;
            return;
        }
        v = (1 << msb) + vDiff;
    }
    if (v == 0 || (v == 1 && (vals[0] - subtract[0] > 0))){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    return;
}

void solve(int tt) {
    ll m; cin >> m;
    forn(i, m){
        ll t; cin >> t;
        if (t == 1){
            ll v; cin >> v;
            vals[v]++;
        }
        if (t == 2){
            query();
        }
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