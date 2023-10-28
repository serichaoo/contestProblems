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
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    str s;
    cin >> s;
    ll l = s.size();
    ll pos;
    ll newSize = l;
    cin >> pos;
    while (pos > newSize)
    {
        pos -= newSize;
        newSize--;
    }
    // take minimum lexicographical substring from left to right, take the position
    // take first element to be the first minimum element of the first l-newSize+1 positions
    // take ith element as the min between pos[i-1], l - newSize + i
    char minChar = 'z' + 1;
    deque<ll> minCharPos;
    ll startPos = 0;
    for (ll i = 0; i < pos; i++)
    {
        for (ll j = startPos; j < l - newSize + i + 1; j++)
        {
            if (j == startPos && minCharPos.size() != 0)
                j = minCharPos[minCharPos.size() - 1] + 1;
            if (s[j] < minChar)
            {
                minCharPos.clear();
                minChar = s[j];
                minCharPos.push_back(j);
            }
            else if (s[j] == minChar)
            {
                minCharPos.push_back(j);
            }
        }
        startPos = minCharPos[0] + 1;
        minCharPos.pop_front();
        if (minCharPos.size() == 0)
            minChar = 'z' + 1;
    }
    cout << s[startPos - 1];
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