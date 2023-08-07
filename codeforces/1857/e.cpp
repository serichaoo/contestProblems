#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <math.h>
#include <set>
#include <algorithm>

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
    vector<vi> lengths(n, vi(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            lengths[i][j] = abs(ints[j] - ints[i]) + 1;
            lengths[j][i] = lengths[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        ll count = 0;
        for (int j = 0; j < n; j++)
        {
            count += lengths[i][j];
        }
        cout << count << ' ';
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