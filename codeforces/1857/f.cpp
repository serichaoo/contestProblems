#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <math.h>
#include <set>

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
    multiset<ll> a;
    for (int i = 0; i < n; i++)
    {
        ll b;
        cin >> b;
        a.insert(2 * b);
    }
    int q;
    cin >> q;
    ll x, y;
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        x *= 2;
        y *= 4;
        ll r1, r2;
        // disc = sqrt(x^2-4y), check if perfect square
        ll discriminant = (x / 2) * (x / 2) - y;
        ll sr = (ll)(sqrt(discriminant) + 0.000001);
        if (sr * sr != discriminant)
        {
            if ((sr - 1) * (sr - 1) != discriminant)
            {
                if ((sr + 1) * (sr + 1) != discriminant)
                {
                    cout << 0 << ' ';
                    continue;
                }
                sr += 1;
            }
            sr -= 1;
        }
        r1 = x / 2 - sr;
        r2 = x / 2 + sr;
        if (r1 != r2)
            cout << a.count(r1) * a.count(r2) << ' ';
        else
            cout << a.count(r1) * (a.count(r1) - 1) / 2 << ' ';
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