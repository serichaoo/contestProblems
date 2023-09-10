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
const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-9;

ll numMoves(ll a, ll b, bool sameIndex)
{
    if (!sameIndex)
    {
        ll c = a | b;
        ll d = max(a ^ c, b ^ c);
        bool isEqual = 0;
        if (d == 0)
            isEqual = 1;
        while (d > 0)
        {
            c = c >> 1;
            d = d >> 1;
        }
        ll count = 0;
        while (c > 0)
        {
            c &= c - 1;
            count++;
        }
        count += 1;
        if (!isEqual)
        {
            return 2 * count + 1;
        }
        else
        {
            return 2 * count;
        }
    }
    else
    {
        ll count = 0;
        while (a > 0)
        {
            a &= a - 1;
            count++;
        }
        return count + 1;
    }
}
ll myPow(ll x, ll po)
{
    x %= MOD;
    if (po == 0)
        return 1;
    if (po == 1)
        return x;
    ll half = myPow(x, po / 2);
    if (po % 2 == 0)
        return ((half * half) % MOD);
    else
        return ((x * ((half * half) % MOD)) % MOD);
}
void solve()
{
    int n;
    cin >> n;
    vll nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += numMoves(nums[i], nums[i], true);
        sum %= MOD;
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            sum += numMoves(nums[i], nums[j], false);
            sum %= MOD;
        }
    ll denom = myPow(n * n, MOD - 2);
    sum *= denom;
    sum %= MOD;
    cout << sum << endl;
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