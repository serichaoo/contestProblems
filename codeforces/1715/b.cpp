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
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    if (!(s - n * (k - 1) <= b * k && s >= b * k))
        cout << -1 << endl;
    else
    {
        vll ints(n);
        ll placeholder = s;
        ll curVal = 0;
        ll space = 0;
        ll placeholderPos = INF;
        for (ll i = 0; i < n - 1; i++)
        {
            if (placeholder >= k)
            {
                ints[i] = k;
                placeholder -= k;
                curVal++;
            }
            else
            {
                ints[i] = placeholder;
                placeholder = 0;
                space += k - 1 - placeholder;
                placeholderPos = min(placeholderPos, i);
            }
        }
        ints[n - 1] = placeholder;
        curVal += placeholder / k;
        space += k - 1 - placeholder;
        if (space < 0)
            space = (space % k) + k;
        placeholderPos = min(placeholderPos, n - 1);
        if (curVal < b)
            cout << -1 << endl;
        ll it = 0;
        while (curVal > b)
        {
            if (it < placeholderPos)
            {
                ints[it]--;
                space--;
                curVal--;
                for (ll i = placeholderPos; i < n; i++)
                {
                    if ((ints[i] % k) != k - 1 || i == n - 1)
                    {
                        ints[i]++;
                        break;
                    }
                }
                if (space < 0)
                {
                    curVal++;
                    space += k;
                }
            }
            else
            {
                cout << -1 << endl;
                return;
            }
            it++;
        }
        for (int i = 0; i < n; i++)
            cout << ints[i] << ' ';
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