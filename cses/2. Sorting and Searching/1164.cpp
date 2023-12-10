#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back;
#define forn(i, n) for (int i = 0; i < int(n); i++)

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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

bool multiTest = 0;

void solve(int tt)
{
    ll n;
    cin >> n;
    vector<pll> times;
    set<tuple<ll, ll, ll>> event;
    map<pll, vll> toIndices;
    vll rooms(n);
    ll k = 0;
    ll curOccupied = 0;
    forn(i, n)
    {
        ll a, b;
        cin >> a >> b;
        times.push_back({a, b});
        event.insert({a, -1, i});
        event.insert({b, 1, i});
    }
    for (auto x : event)
    {
        if (get<1>(x) == -1)
        {
            curOccupied++;
            k = max(k, curOccupied);
        }
        else
        {
            curOccupied--;
        }
    }
    set<ll> unoccupiedRooms;
    forn(i, k)
        unoccupiedRooms.insert(i + 1);
    for (auto x : event)
    {
        if (get<1>(x) == -1)
        {
            auto r = unoccupiedRooms.begin();
            rooms[get<2>(x)] = *r;
            unoccupiedRooms.erase(r);
        }
        if (get<1>(x) == 1)
        {
            unoccupiedRooms.insert(rooms[get<2>(x)]);
        }
    }
    cout << k << endl;
    forn(i, n)
            cout
        << rooms[i] << ' ';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    if (multiTest)
        cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        solve(ii);
    }
}