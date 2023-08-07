#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

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

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll x = a * d;
    ll y = b * c;
    if (x == y)
    {
        cout << 0 << endl;
        return;
    }
    if (x == 0 || y == 0)
    {
        cout << 1 << endl;
        return;
    }
    if ((x % y) == 0 || (y % x) == 0)
    {
        cout << 1 << endl;
        return;
    }
    else
        cout << 2 << endl;
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