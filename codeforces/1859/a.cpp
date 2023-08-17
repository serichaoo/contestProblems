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
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    int n;
    cin >> n;
    int max = 0;
    vi maxIndex;
    int min = INF;
    int minIndex = -1;
    vi ints(n);
    for (int i = 0; i < n; i++)
        cin >> ints[i];
    for (int i = 0; i < n; i++)
    {
        if (ints[i] > max)
        {
            max = ints[i];
            maxIndex.clear();
            maxIndex = {i};
        }
        else if (ints[i] == max)
        {
            maxIndex.push_back(i);
        }
        if (ints[i] < min)
        {
            min = ints[i];
            minIndex = i;
        }
    }
    if (min == max)
    {
        cout << -1 << endl;
        return;
    }
    vector<bool> isMax(n, false);
    for (int i = 0; i < maxIndex.size(); i++)
    {
        isMax[maxIndex[i]] = true;
    }
    cout << n - maxIndex.size() << ' ' << maxIndex.size() << endl;
    for (int i = 0; i < n; i++)
    {
        if (!isMax[i])
        {
            cout << ints[i] << ' ';
        }
    }
    cout << endl;
    for (int i = 0; i < maxIndex.size(); i++)
    {
        cout << max << ' ';
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