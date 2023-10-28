#include <bits/stdc++.h>
// codeforces general template taken from https://ncduy0303.github.io/Competitive-Programming/Contest%20Template/main.cpp
// template snippet prepared ahead of time, not during the contest
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
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pll> rain(m);
    vector<bool> rainChanges(n + 1);
    map<ll, vll> changeCityToRainIndex;
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        rain[i] = {a, b};
        rainChanges[a] = true;
        rainChanges[b + 1] = true;
        changeCityToRainIndex[a].push_back(i + 1);
        changeCityToRainIndex[b + 1].push_back(-i - 1);
    }
    set<ll> rainingIndices;
    ll dryCities = 0;
    vll removeOneEffect(m);
    map<pll, ll> removeTwoEffect;
    for (int i = 0; i < n; i++)
    {
        if (rainChanges[i])
        {
            vll a = changeCityToRainIndex[i];
            for (ll x : a)
            {
                if (x > 0)
                    rainingIndices.insert(x);
                else
                    rainingIndices.erase(-x);
            }
        }
        if (rainingIndices.size() == 0)
            dryCities++;
        else if (rainingIndices.size() == 1)
            removeOneEffect[*rainingIndices.begin() - 1]++;
        else if (rainingIndices.size() == 2)
        {
            ll a = *rainingIndices.begin() - 1;
            ll b = *(++rainingIndices.begin()) - 1;
            removeTwoEffect[{a, b}]++;
            removeTwoEffect[{b, a}]++;
        }
    }
    ll maxRemoval = 0;
    for (auto key : removeTwoEffect)
    {
        maxRemoval = max(maxRemoval, key.second + removeOneEffect[key.first.first] + removeOneEffect[key.first.second]);
        // key.second += removeOneEffect[key.first.first] + removeOneEffect[key.first.second];
    }
    sort(all(removeOneEffect));
    maxRemoval = max(maxRemoval, removeOneEffect[m - 1] + removeOneEffect[m - 2]);
    cout << dryCities + maxRemoval << endl;
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