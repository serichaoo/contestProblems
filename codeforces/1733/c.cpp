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
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    cout << n - 1 << endl;
    vector<bool> editedList(n, false);
    if ((ints[0] % 2) == 1)
    {
        cout << 1 << ' ' << n << endl;
        for (int i = 1; i < n - 1; i++)
            if ((ints[i] % 2) == 0)
            {
                cout << 1 << ' ' << i + 1 << endl;
                editedList[i] = true;
            }
        for (int i = 1; i < n - 1; i++)
        {
            if (!editedList[i])
                cout << i + 1 << ' ' << n << endl;
        }
    }
    else
    {
        cout << 1 << ' ' << n << endl;
        for (int i = 1; i < n - 1; i++)
            if ((ints[i] % 2) == 1)
            {
                cout << 1 << ' ' << i + 1 << endl;
                editedList[i] = true;
            }
        for (int i = 1; i < n - 1; i++)
        {
            if (!editedList[i])
                cout << i + 1 << ' ' << n << endl;
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