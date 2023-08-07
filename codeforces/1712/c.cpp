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
    vll ints;
    map<ll, vll> valToIndices;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (i > 0)
            if (a == ints[sza(ints) - 1])
                continue;
        ints.push_back(a);
    }
    n = sza(ints);
    for (int i = 0; i < n; i++)
        valToIndices[ints[i]].push_back(i);
    reverse(all(ints));
    set<ll> allBadInts;
    for (auto it : valToIndices)
    {
        if (it.second.size() > 1)
        {
            allBadInts.insert(it.first);
        }
    }
    if (allBadInts.count(ints[0]) == 0)
    {
        int curLength = 1;
        // vll allGoodInts;
        for (int i = 1; i < n; i++)
        {
            if (ints[i] < ints[i - 1] && allBadInts.count(ints[i]) == 0)
            {
                curLength++;
                // allGoodInts.push_back(ints[i]);
            }
            else
                break;
        }
        cout << valToIndices.size() - curLength << endl;
    }
    else
    {
        cout << valToIndices.size() << endl;
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