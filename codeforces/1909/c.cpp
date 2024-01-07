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
// largest cost goes to shortest interval
// try to create the most variance
// pair lowest number with highest that can be paired with and still finish pairings
    ll n; cin >> n;
    vll l(n);
    vll r(n);
    multiset<ll> c;
    forn(i, n){
        cin >> l[i];
    }
    forn(i, n)
        cin >> r[i];
    forn(i, n)
        {
            ll ci; cin >> ci;
            c.insert(ci);
        }
    sort(all(l));
    sort(all(r));
   // sort(all(c));
    vll numPairable(n);
    ll p1 = n-1; ll p2 = n-1;
    while (p1 >= 0){
        while (l[p1] < r[p2] && p2 >= 0){
            p2--;
        }
        numPairable[p1] = n - p2 - 1 - (n-1-p1);
        p1--;
    }
    stack<ll> increase;
    multiset<ll> lengths;
    vector<bool> processed(n);
    for (int i=1; i< n; i++){
        if (numPairable[i] - numPairable[i-1] > 0){
            increase.push(i-1);
            processed[i-1] = 1;
        }
        if (numPairable[i] - numPairable[i-1] < 0){
            ll x = numPairable[i-1] - numPairable[i];
            for (int j=x-1; j>=0; j--){
                ll a = increase.top();
                lengths.insert(r[i-1-j] - l[a]);
                increase.pop();
            }
        }
    }
    while (!increase.empty()){
        ll x = increase.size();
        ll i = n;
        for (int j=x-1; j>=0; j--){
            ll a = increase.top();
            lengths.insert(r[i-1-j] - l[a]);
            increase.pop();
        }
    }
    for (int i=0; i<n; i++){
        if (!processed[i]){
            ll left = l[i];
            ll right = *upper_bound(all(r), left);
            lengths.insert(right - left);
        }
    }

    auto itLength = lengths.begin();
    auto itCost = c.end();
    ll ans = 0;
    forn(i, n){
        itCost--;
        ans += (*itLength) * (*itCost);
        itLength++;
    }
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