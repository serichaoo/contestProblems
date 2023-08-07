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
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    vi indexToBox(n);
    vi boxNumIndices(n, 0);
    vi boxMaxIndices(n, -1);
    vi dMin(n);
    vi dMax(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int curBoxIndex = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        while (curBoxIndex < n - 1 && b[i] >= a[curBoxIndex + 1])
        {
            curBoxIndex++;
        }
        indexToBox[i] = curBoxIndex;
        boxMaxIndices[curBoxIndex] = max(boxMaxIndices[curBoxIndex], i);
        boxNumIndices[curBoxIndex]++;
    }
    int p1 = 0;
    int p2 = 0;
    while (p1 < n)
    {
        if (b[p2] >= a[p1])
        {
            dMin[p1] = b[p2] - a[p1];
            p1++;
        }
        else
            p2++;
    }
    for (int i = 0; i < n; i++)
        cout << dMin[i] << ' ';
    cout << endl;
    // find bottleneck points
    set<int> bottleneckPoints{-1};
    int curVal = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (curVal == 0)
            bottleneckPoints.insert(i);
        curVal += boxNumIndices[i] - 1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (bottleneckPoints.count(i))
            dMax[i] = b[boxMaxIndices[i]] - a[i];
        else
        {
            int minAffected = *(--bottleneckPoints.lower_bound(i)) + 1;
            for (int j = minAffected; j <= i; j++)
                dMax[j] = b[boxMaxIndices[i + 1]] - a[j];
            i = minAffected;
        }
    }
    for (int i = 0; i < n; i++)
        cout << dMax[i] << ' ';
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