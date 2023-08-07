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
    ll n, q;
    cin >> n >> q;
    vll a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pii> interval(n, {0, 0}); // interval of victories, total is second-first
    ll curMatch = 0;
    ll curMax = a[0];
    ll curMaxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[curMaxIndex] > a[i])
        {
            interval[curMaxIndex].second++;
            curMatch++;
        }
        else
        {
            curMax = a[i];
            curMaxIndex = i;
            interval[i].first = curMatch;
            curMatch++;
            interval[i].second = curMatch;
        }
    }
    interval[curMaxIndex].second = INF;
    for (int i = 0; i < q; i++)
    {
        int index, e;
        cin >> index >> e;
        index--;
        cout << max(min(interval[index].second, e) - interval[index].first, 0) << endl;
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