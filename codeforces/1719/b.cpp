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
    ll n, k;
    cin >> n >> k;
    if ((k % 2) == 1)
    {
        cout << "YES" << endl;
        for (int i = 1; i <= n / 2; i++)
        {
            cout << 2 * i - 1 << ' ' << 2 * i << endl;
        }
    }
    else
    {
        if (k % 4 == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (int i = 1; i <= n / 2; i++)
            {
                if ((i % 2) == 1)
                    cout << 2 * i << ' ' << 2 * i - 1 << endl;
                else
                    cout << 2 * i - 1 << ' ' << 2 * i << endl;
            }
        }
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