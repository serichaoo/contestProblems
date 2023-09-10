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
    int a, b, n;
    cin >> a >> b >> n;
    if (b - a < n * (n - 1) / 2)
    {
        cout << -1 << endl;
        return;
    }
    vi ans(n);
    ans[0] = a;
    for (int i = 0; i < n - 1; i++)
        ans[n - 1 - i] = b - (i) * (i + 1) / 2;
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
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