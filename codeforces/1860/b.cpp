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
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    ll m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    ll fancyCoinsUsed = 0;

    ll num1s = m % k;
    if ((a1 - num1s) / k > 0)
    {
        ak += (a1 - num1s) / k;

        a1 = ((a1 - num1s) % k) + num1s;
    }
    ll numks = m / k;
    if (ak < numks)
        fancyCoinsUsed += numks - ak;
    if (a1 < num1s)
        fancyCoinsUsed += num1s - a1;
    cout << fancyCoinsUsed << endl;
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