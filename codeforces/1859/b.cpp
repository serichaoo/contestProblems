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
    vector<vll> ints(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        ints[i] = vll(m);
        for (int j = 0; j < m; j++)
            cin >> ints[i][j];
        sort(all(ints[i]));
    }
    int min1 = INF;
    int min1Index = -1;
    for (int i = 0; i < n; i++)
    {
        int placeholder = ints[i][1];
        if (placeholder < min1)
        {
            min1 = placeholder;
            min1Index = i;
        }
    }
    // find absolute min
    int min = INF;
    for (int i = 0; i < n; i++)
    {
        if (ints[i][0] < min)
        {
            min = ints[i][0];
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != min1Index)
            ans += ints[i][1];
        else
            ans += min;
    }
    cout << ans << endl;
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