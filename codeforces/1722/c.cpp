#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

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
    map<string, vi> words;
    int n;
    cin >> n;
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < n; i++)
        {
            string a;
            cin >> a;
            words[a].push_back(j);
        }
    vi points(3, 0);
    for (auto it : words)
    {
        if (it.second.size() == 2)
        {
            points[it.second[0]]++;
            points[it.second[1]]++;
        }
        if (it.second.size() == 1)
        {
            points[it.second[0]] += 3;
        }
    }
    cout << points[0] << ' ' << points[1] << ' ' << points[2] << endl;
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