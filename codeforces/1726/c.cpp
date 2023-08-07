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

vi ints;
unordered_map<int, vi> valToIndices;

int number(int start, int end)
{
    int n = end - start;
    if (n == 0)
        return 0;
    if (n == 2)
        return 1;
    vi zeroIndices = valToIndices[ints[start] - 1];
    auto firstIt = lower_bound(zeroIndices.begin(), zeroIndices.end(), start - 1);
    auto lastIt = lower_bound(zeroIndices.begin(), zeroIndices.end(), end);
    vi newZeroIndices(firstIt, lastIt);
    int ans = 1;
    for (int i = 1; i < newZeroIndices.size(); i++)
    {
        ans += number(newZeroIndices[i - 1] + 2, newZeroIndices[i]);
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    ints.resize(2 * n);
    ints[0] = 1;
    valToIndices[0].push_back(-1);
    valToIndices[1].push_back(0);
    char a;
    cin >> a;
    for (int i = 1; i < 2 * n; i++)
    {
        cin >> a;
        if (a == '(')
            ints[i] = ints[i - 1] + 1;
        else
            ints[i] = ints[i - 1] - 1;
        valToIndices[ints[i]].push_back(i);
    }
    cout << number(0, 2 * n) << endl;
    ints.clear();
    valToIndices.clear();
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