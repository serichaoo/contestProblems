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

struct portal
{
    ll l, r, a, b;
};

bool operator>(portal a, portal b)
{
    return a.l > b.l;
}

void solve()
{ // keep teleporting as far right as possible
    int nPortals;
    cin >> nPortals;
    vector<portal> portals(nPortals);
    for (int i = 0; i < nPortals; i++)
    {
        ll l, r, a, b;
        cin >> l >> r >> a >> b;
        portals[i] = {l, r, a, b};
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