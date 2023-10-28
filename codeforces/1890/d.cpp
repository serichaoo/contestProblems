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
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const ld EPS = 1e-9;

bool operator<(pll a, pll b)
{
    return a.first < b.first;
}

void solve()
{
    ll n, c;
    cin >> n >> c;
    vll a(n);
    vll toConnect(n - 1);
    vector<pll> vals(n - 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        toConnect[i] = i + 1;
        vals[i] = {-(a[i + 1] - (i + 2) * c), i + 1};
    }
    ll oneComponentSize = a[0];
    sort(all(vals));
    for (int i = 0; i < n - 1; i++)
    {
        if (oneComponentSize - vals[i].first >= 0)
        {
            oneComponentSize += a[vals[i].second];
        }
        else
        {
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
    return;
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