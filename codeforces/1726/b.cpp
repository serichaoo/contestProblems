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
    int n, m;
    cin >> n >> m;
    if (n > m)
    {
        cout << "NO" << endl;
        return;
    }
    if ((n % 2 == 0) && (m % 2 == 1))
    {
        cout << "NO" << endl;
        return;
    }
    vi ints(n);
    if ((n % 2 == 0))
    {
        for (int i = 0; i < n - 2; i++)
            ints[i] = 1;
        ints[n - 2] = (m - n + 2) / 2;
        ints[n - 1] = ints[n - 2];
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
            ints[i] = 1;
        ints[n - 1] = m - n + 1;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
        cout << ints[i] << ' ';
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