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

bool multiTest = 0;

// bool greaterVLL(vll a, vll b)
// {
//     if (a[0] != b[0]) return a[0] < b[0];
//     if (a[1] != b[1]) return a[1] < b[1];
//     return a[2] < b[2];
// }

ll n;
vector<tuple<ll, ll, ll>> projects;
vector<pll> projectsByStart;
ll maxTime = 0;
vll val;
vector<bool> calculated;
ll dp(ll time){
    if (time == maxTime) return 0;
    if (calculated[time]) return val[time];
    ll ans = dp(time+1);
    auto it = lower_bound(all(projectsByStart), make_pair(time, ll(0)));
    while (it != projectsByStart.end() && it->first == time){
        ans = max(ans, get<2>(projects[it->second]) + dp(get<1>(projects[it->second])));
        it++;
    }
    calculated[time] = 1;
    val[time] = ans;
    return ans;
}

void solve(int tt)
{
    cin >> n;
    set<ll> times;
    forn(i, n){
        ll a, b, p;
        cin >> a >> b >> p;
        b++;
        times.insert(a);
        times.insert(b);
        projects.pb({a, b, p});
    }
    map<ll, ll> timeCompression;
    for (ll x : times){
        timeCompression[x] = maxTime;
        maxTime++;
    }
    val.resize(maxTime);
    forn(i, n){
        get<0>(projects[i]) = timeCompression[get<0>(projects[i])];
        get<1>(projects[i]) = timeCompression[get<1>(projects[i])];
    }
    sort(all(projects));
    projectsByStart.resize(n);
    calculated.resize(maxTime);
    forn(i, n)
        projectsByStart[i] = make_pair(get<0>(projects[i]), i);
    cout << dp(0);
}

signed main()
{
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