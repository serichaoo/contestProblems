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
const ll INF = 2e18;
const ld EPS = 1e-9;

map<ll, ll> indexChangeVals;
map<ll, ll> lengths;

ll intPow(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    return (intPow(a * a, b / 2) * intPow(a, b % 2));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    indexChangeVals[4] = 2;
    indexChangeVals[8] = 1;
    indexChangeVals[9] = 2;
    indexChangeVals[729] = 3;
    indexChangeVals[intPow(15, 4)] = 4;
    indexChangeVals[intPow(21, 5)] = 5;
    indexChangeVals[intPow(28, 6)] = 6;
    indexChangeVals[intPow(35, 7)] = 7;
    indexChangeVals[intPow(43, 8)] = 8;
    indexChangeVals[intPow(50, 9)] = 9;
    indexChangeVals[intPow(58, 10)] = 10;
    indexChangeVals[INF] = 11;
    ll q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        ll l, r;
        ll ans = 0;
        cin >> l >> r;
        auto a = --indexChangeVals.upper_bound(l);
        auto b = --indexChangeVals.upper_bound(r);
        if (a == b)
        {
            ans = (((r - l + 1) % MOD) * a->second) % MOD;
        }
        else
        {
            ll val = a->second;
            a = indexChangeVals.upper_bound(l);
            ans += ((a->first) - l) * val;
            ans %= MOD;
            while (a != b)
            {
                a++;
                ll x, y;
                x = a->first;
                y = (--a)->first;
                ans += ((x - y) % MOD) * a->second;
                a++;
                ans %= MOD;
            }
            ans += ((r - (b->first) + 1) % MOD) * b->second;
            ans %= MOD;
        }
        cout << ans << endl;
    }

    return 0;
}