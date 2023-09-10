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

ll mod(ll a, ll b)
{
    return (((a % b) + b) % b);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    if (m == 1)
    {
        cout << 0 << endl;
        for (int i = 0; i < n; i++)
            cout << 0 << endl;
        return;
    }
    cout << min(m, n + 1) << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i < m - 1)
            {
                cout << mod(j - i, m) << ' ';
            }
            else
            {
                cout << j << ' ';
            }
        }
        cout << endl;
    }
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