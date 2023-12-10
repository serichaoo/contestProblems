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
    ll n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    ll leftIndex = 0;
    ll rightIndex = n - 1;
    ll x = 0;
    ll ans = 0;
    while (leftIndex < rightIndex)
    {
        if (x + a[leftIndex] < a[rightIndex])
        {
            ans += a[leftIndex];
            x += a[leftIndex];
            leftIndex++;
        }
        else if (x + a[leftIndex] == a[rightIndex])
        {
            ans += a[leftIndex] + 1;
            x = 0;
            leftIndex++;
            rightIndex--;
        }
        else
        {
            ll val = a[rightIndex] - x;
            x = 0;
            ans += val + 1;
            a[leftIndex] -= val;
            rightIndex--;
        }
    }
    if (leftIndex > rightIndex)
    {
        cout << ans << endl;
        return;
    }
    else
    {
        if (a[leftIndex] == 1)
        {
            ans++;
        }
        else
        {
            ll d = (a[leftIndex] - x) / 2;
            x += d;
            a[leftIndex] -= d;
            ans += d;
            a[leftIndex] -= x;
            ans++;
            if (a[leftIndex] == 1)
                ans++;
        }
        cout << ans << endl;
        return;
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