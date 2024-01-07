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
    // do dp, store state as a triple
    ll n; cin >> n;
    set<tuple<ll, ll, ll>> states = {{0, -INF, -INF}}; // always sort so that |second element| > |third element|
    vll a(n);
    forn(i, n) cin >> a[i];
    forn(i, n){
        auto it = states.begin();
        ll ans = get<0>(*it);
        ll v1 = -get<1>(*it);
        ll v2 = -get<2>(*it);
        if (a[i] <= v2){
            states.clear();
            states.insert({ans, -v1, -a[i]});
            continue;
        }
        else if (a[i] <= v1){
            states.clear();
            states.insert({ans, -a[i], -v2});
            continue;
        }
        else{
            tuple<ll, ll, ll> newState1 = {ans+1, -a[i], -v1};
            tuple<ll, ll, ll> newState2 = {-1, -1, -1};
            auto it2 = states.lower_bound({ans+1, -INF, -INF});
            if (it != states.end()){
                ll v3 = -get<1>(*it2);
                ll v4 = -get<2>(*it2);
                if (a[i] <= v4){
                    newState2 = {ans+1, -v3, -a[i]};
                }
                else if (a[i] <= v1){
                    newState2 = {ans+1, -a[i], -v4};
                }
            }
            states.clear();
            states.insert(newState1);
            if (get<0>(newState2) != -1)
            states.insert(newState2);
        }
    }
    cout << get<0>(*states.begin()) << endl;
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