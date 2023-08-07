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
    ll n;
    cin >> n;
    vector<bool> line(n);
    ll curVal = 0;
    for (ll i = 0; i < n; i++)
    {
        char a;
        bool b;
        cin >> a;
        if (a == 'L')
        {
            b = 0;
            curVal += i;
        }
        else
        {
            b = 1;
            curVal += (n - 1 - i);
        }
        line[i] = b;
    }
    vector<bool> leftLine(n / 2);
    for (int i = 0; i < n / 2; i++)
        leftLine[i] = line[i];
    vector<bool> rightLine(n / 2);
    for (int i = 0; i < n / 2; i++)
        rightLine[i] = line[(n + 1) / 2 + i];
    reverse(all(rightLine));
    ll lp = 0;
    ll rp = 0;
    int k = 0;
    while (lp < n / 2)
    {
        if (leftLine[lp] == 0)
        {
            leftLine[lp] = 1;
            curVal += n - 1 - lp - lp;
            cout << curVal << ' ';
            k++;
            continue;
        }
        if (rightLine[rp] == 1)
        {
            rightLine[rp] = 0;
            curVal += n - 1 - rp - rp;
            cout << curVal << ' ';
            k++;
            continue;
        }
        lp++;
        rp++;
    }
    for (int i = 0; i < n - k; i++)
        cout << curVal << ' ';
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