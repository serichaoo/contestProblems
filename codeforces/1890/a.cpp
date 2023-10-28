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
    ll count1 = 0;
    ll count2 = 0;
    ll val1 = 0, val2 = 0;
    bool possible = true;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        if (a == val1)
            count1++;
        if (a == val2)
            count2++;
        if (val1 == 0)
        {
            val1 = a;
            count1++;
        }
        else if (val2 == 0 && a != val1)
        {
            val2 = a;
            count2++;
        }
        if (a != val1 && a != val2)
        {
            possible = false;
        }
    }
    if (val2 == 0 || (n / 2 == min(count1, count2) && (n + 1) / 2 == max(count1, count2) && possible))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
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