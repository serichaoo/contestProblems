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
    ll n, m;
    cin >> n >> m;
    str s, t;
    cin >> s >> t;
    bool zeroBad = false;
    bool oneBad = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            if (s[i] == '0')
                zeroBad = true;
            else
                oneBad = true;
        }
    }
    if (!(zeroBad) && !(oneBad))
    {
        cout << "yes" << endl;
        return;
    }
    if (zeroBad && oneBad)
    {
        cout << "no" << endl;
        return;
    }
    bool tBad = false;
    for (int i = 0; i < m - 1; i++)
    {
        if (t[i] == t[i + 1])
        {
            tBad = true;
        }
    }
    if (tBad)
    {
        cout << "no" << endl;
        return;
    }
    if (t[0] != t[m - 1])
    {
        cout << "no" << endl;
        return;
    }
    if ((t[0] == '0' && oneBad) || (t[0] == '1' && zeroBad))
    {
        cout << "yes" << endl;
        return;
    }
    else
    {
        cout << "no" << endl;
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