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
    int n, x, y;
    cin >> n >> x >> y;
    if ((x > 0 && y > 0) || max(x, y) == 0)
    {
        cout << -1 << endl;
        return;
    }
    x = max(x, y);
    y = 0;
    if ((n - 1) % x != 0)
    {
        cout << -1 << endl;
        return;
    }
    int counter = (n - 1) / x;
    int start = 2;
    while (counter > 0)
    {
        for (int i = 0; i < x; i++)
            cout << start << ' ';
        counter--;
        start += x;
    }
    cout << endl;
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