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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<bool> a(n);
    vector<bool> b(n);
    ll numOneA = 0;
    ll numOneB = 0;
    for (int i = 0; i < n; i++)
    {
        char m;
        cin >> m;
        m -= '0';
        a[i] = m;
        if (m == 1)
            numOneA++;
    }
    for (int i = 0; i < n; i++)
    {
        char m;
        cin >> m;
        m -= '0';
        b[i] = m;
        if (m == 1)
            numOneB++;
    }

    if ((numOneA % 2) != (numOneB % 2))
    {
        cout << -1 << endl;
        return;
    }

    ll ans = 0;

    if (x >= y)
    {
        vll diffLocations{-2};
        for (int i = 0; i < n; i++)
            if (a[i] != b[i])
                diffLocations.push_back(i);
        diffLocations.push_back(INF);
        for (int i = diffLocations.size() - 2; i > 0; i--)
        {
            if ((diffLocations[i - 1] + 1 == diffLocations[i]) && (diffLocations[i] + 1 == diffLocations[i + 1]))
                for (int j = diffLocations.size() - 2; j > 0; j--)
                    if (abs(diffLocations[i] - diffLocations[j]) > 1)
                    {
                        diffLocations.erase(diffLocations.begin() + min(i, j));
                        diffLocations.erase(diffLocations.begin() + max(i, j) - 1);
                        ans += y;
                        break;
                    }
        }
        for (int i = diffLocations.size() - 2; i > 0; i--)
        {
            if ((diffLocations[i - 1] + 1 == diffLocations[i]) || (diffLocations[i] + 1 == diffLocations[i + 1]))
                for (int j = diffLocations.size() - 2; j > 0; j--)
                    if (abs(diffLocations[i] - diffLocations[j]) > 1)
                    {
                        diffLocations.erase(diffLocations.begin() + min(i, j));
                        diffLocations.erase(diffLocations.begin() + max(i, j) - 1);
                        ans += y;
                        break;
                    }
        }
        if (diffLocations.size() > 2)
        {
            if (diffLocations[1] + 1 == diffLocations[2])
            {
                if (2 * y < x)
                    ans += 2 * y;
                else
                    ans += x;
            }
            else
                ans += y * ((diffLocations.size() - 2) / 2);
        }
    }
    else
    {
        vll diffLocations;
        for (int i = 0; i < n; i++)
            if (a[i] != b[i])
                diffLocations.push_back(i);
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