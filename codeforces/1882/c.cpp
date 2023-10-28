#include <bits/stdc++.h>
// codeforces general template taken from https://ncduy0303.github.io/Competitive-Programming/Contest%20Template/main.cpp
// template snippet prepared ahead of time, not during the contest
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
const ll INF = 1e9;
const ld EPS = 1e-9;

bool lessThan(pair<ll, ll> a, pll b)
{
    return a.second < b.second;
}

void solve()
{ // go from back to front, choosing all odd positive cards
    // then, either take card 1 or remove card 2, then repeat going back to front
    ll ans = 0;
    ll curScore = 0;
    int n;
    cin >> n;
    vll a(n);
    // set<pair<ll, ll>, decltype(lessThan)> vals;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        // vals.insert({a[i], i});
    }
    // for (auto it = --vals.end(); it != vals.begin(); it--)
    // {
    //     int
    // }
    for (int i = 2; i < n; i++)
        if (a[i] > 0)
            ans += a[i];
    if (n >= 2 && a[0] > 0 && a[1] > 0)
        ans += a[0] + a[1];
    else if (a[0] > 0)
        ans += a[0];
    else if (n >= 2 && a[0] + a[1] > 0)
        ans += a[0] + a[1];
    cout << ans << endl;
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