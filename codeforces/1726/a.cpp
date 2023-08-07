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
    int n;
    cin >> n;
    vi ints(n);
    for (int i = 0; i < n; i++)
        cin >> ints[i];
    int maxVal = 0;
    for (int i = 0; i < n; i++)
        maxVal = max(maxVal, ints[i] - ints[(i + 1) % n]);

    int minValue = INF;
    int maxValue = 0;
    for (int i = 0; i < n; i++)
    {
        minValue = min(minValue, ints[i]);
        maxValue = max(maxValue, ints[i]);
    }
    maxVal = max(maxVal, maxValue - ints[0]);
    maxVal = max(maxVal, ints[n - 1] - minValue);
    cout << maxVal << endl;
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