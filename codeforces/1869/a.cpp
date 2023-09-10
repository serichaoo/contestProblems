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
    int n;
    cin >> n;
    vi ints(n);
    for (int i = 0; i < n; i++)
        cin >> ints[i];
    if (n % 2 == 0)
    {
        cout << 2 << endl
             << 1 << ' ' << n << endl
             << 1 << ' ' << n << endl;
        return;
    }
    else
    {
        cout << 4 << endl
             << 1 << ' ' << n << endl
             << 1 << ' ' << n - 1 << endl
             << n - 1 << ' ' << n << endl
             << n - 1 << ' ' << n << endl;
        return;
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