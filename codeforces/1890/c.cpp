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
    str s;
    cin >> n >> s;
    if (n % 2)
    {
        cout << -1 << endl;
        return;
    }
    ll count0 = 0;
    ll count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            count0++;
        else
            count1++;
    }
    if (count0 != count1)
    {
        cout << -1 << endl;
        return;
    }
    vll insertLocations;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == s[n - 1 - i])
        {
            if (s[i] == '0')
            {
                insertLocations.push_back(n - i);
                // str a = s.substr(0, n - i);
                // str b = s.substr(n - i - 1, i);
                s = s.substr(0, n - i) + "01" + s.substr(n - i, i);
                n += 2;
            }
            else
            {
                insertLocations.push_back(i);
                s = s.substr(0, i) + "01" + s.substr(i, n - i);
                n += 2;
            }
        }
    }
    cout << insertLocations.size() << endl;
    for (int i = 0; i < insertLocations.size(); i++)
        cout << insertLocations[i] << ' ';
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