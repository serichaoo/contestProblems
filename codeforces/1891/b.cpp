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

bool operator<(pll a, pll b)
{
    return a.second < b.second;
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    vll a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> pow2(n);
    for (int i = 0; i < n; i++)
    {
        ll b = a[i];
        ll cnt = 0;
        while (!(b % 2))
        {
            b /= 2;
            cnt++;
        }
        pow2[i] = cnt;
    }
    vll qu(1);
    cin >> qu[0];
    for (int i = 1; i < q; i++)
    {
        ll a;
        cin >> a;
        if (a >= qu[qu.size() - 1])
            continue;
        qu.push_back(a);
    }
    q = qu.size();
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll b = a[j];
            ll cnt = 0;
            while ((b % 2) == 0)
            {
                b /= 2;
                cnt++;
            }
            if (cnt >= qu[i])
                a[j] += (1 << (qu[i] - 1));
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
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