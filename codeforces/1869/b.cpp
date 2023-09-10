#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back;

using ld = long double;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e12;
const ld EPS = 1e-9;

ll dist(pair<ll, ll> a, pair<ll, ll> b)
{
    return (abs(a.first - b.first) + abs(a.second - b.second));
}

void solve()
{
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    a--;
    b--;
    vector<pair<ll, ll>> cities(n);
    for (int i = 0; i < n; i++)
        cin >> cities[i].first >> cities[i].second;
    ll curMin = dist(cities[a], cities[b]);
    ll minDistToMajorCity = INF;
    for (int i = 0; i < k; i++)
        minDistToMajorCity = min(dist(cities[a], cities[i]), minDistToMajorCity);
    ll minDistFromMajorCityToB = INF;
    for (int i = 0; i < k; i++)
        minDistFromMajorCityToB = min(dist(cities[b], cities[i]), minDistFromMajorCityToB);
    curMin = min(curMin, minDistToMajorCity + minDistFromMajorCityToB);
    cout << curMin << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();

    return 0;
}