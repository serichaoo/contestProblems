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

vll pow2;

void solve()
{ // go down to the nearest power of 2, then go down by dividing by 2 each time
    int x;
    cin >> x;
    int bits = x;
    bits |= bits >> 1;
    bits |= bits >> 2;
    bits |= bits >> 4;
    bits |= bits >> 8;
    bits |= bits >> 16;
    bits = bits + 1;
    bits = bits >> 1;
    int toRemove = x - bits;
    int removeVal = 1;
    vi sequence{x};
    while (toRemove > 0)
    {
        if (toRemove % 2)
        {
            x -= removeVal;
            sequence.push_back(x);
        }
        toRemove /= 2;
        removeVal *= 2;
    }
    while (x != 1)
    {
        bits /= 2;
        x -= bits;
        sequence.push_back(x);
    }
    cout << sequence.size() << endl;
    for (int i = 0; i < sequence.size(); i++)
    {
        cout << sequence[i] << ' ';
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll val = 1;
    while (val < 1e9)
    {
        pow2.push_back(val);
        val *= 2;
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();

    return 0;
}