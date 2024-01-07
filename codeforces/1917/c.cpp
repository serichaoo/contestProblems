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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
    ll n, k, d; cin >> n >> k >> d;
    vll a(n);
    forn(i, n)
        cin >> a[i];
    vll b(k);
    ll maxB = 0;
    forn(i, k)
        cin >> b[i];
    forn(i, k)
        maxB = max(maxB, b[i]);
    // if first operation2 is on day i (0 <= i < d), then total score += (d-i-1)/2
    // find out the best way to 
    ll ans = 0;
    forn(i, n){
        if (a[i] == i+1)
            ans++;
    }
    ans += (d - 1)/2;
    map<ll, vll> valueIndices;
    forn(i, k){
        valueIndices[b[i]].pb(i);
    }
    ordered_set s;
    multiset<pll> startEnd;
    for (int i=n; i>=1; i--){
        forn(j, valueIndices[i].size()){
            s.insert(valueIndices[i][j]);
            s.insert(valueIndices[i][j]+k);
        }
        if (!s.empty()){
            if (a[i-1] == i){
                startEnd.insert({-1, 1});
                ll x = *s.find_by_order(0);
                startEnd.insert({x, -1});
            }
            if (a[i-1] < i){
                ll x = i - a[i-1];
                ll time = 0;
                if (x > (s.size()/2)){
                    time += ((x-1)/(s.size()/2)) * k;
                    x--;
                    x %= (s.size()/2);
                    x++;
                }
                ll m = *s.find_by_order(x-1);
                ll n = *s.find_by_order(x);
                startEnd.insert({time + m, 1});
                startEnd.insert({time + n, -1});
            }
        }
        else if (a[i-1] == i)
            startEnd.insert({-1, 1});
    }
    ll preTime = -1;
    ll num = 0;
    for (auto it = startEnd.begin(); it != startEnd.end(); it++){
        if (it->first >= d)
            break;
        if (it->first != preTime){
            // process current values
            ans = max(ans, num + (d-preTime -2)/2);
            preTime = it->first;
        }
        if (it->second == 1)
            num++;
        if (it->second == -1)
            num--;
    }
    // cerr << num + (d-preTime -1)/2 << endl;
    if (preTime < d-1)
        ans = max(ans, num + (d-preTime -2)/2);
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