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
const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    str s;
    cin >> s;
    ll numOps = 0;
    ll numWays = 1;
    ll repeatCounter = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            repeatCounter++;
            numOps++;
        }
        else
        {
            numWays *= repeatCounter;
            numWays %= MOD;
            repeatCounter = 1;
        }
    }
    numWays *= repeatCounter;
    numWays %= MOD;
    for (int i = 1; i <= numOps; i++)
    {
        numWays *= i;
        numWays %= MOD;
    }
    cout << numOps << ' ' << numWays << endl;
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