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
{ // iterate through all elements of union of all sets, exclude 1 element, see number of elements
    int n;
    cin >> n;
    vector<set<int>> sets(n);
    set<int> unionAll;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        set<int> ints;
        for (int i = 0; i < k; i++)
        {
            int a;
            cin >> a;
            ints.insert(a);
            unionAll.insert(a);
        }
        sets[i] = ints;
    }
    int ans = 0;
    for (int i = 1; i <= 50; i++)
    {
        if (!unionAll.count(i))
            continue;
        set<int> testSet;
        for (int j = 0; j < n; j++)
        {
            if (!sets[j].count(i))
                for (int a : sets[j])
                    testSet.insert(a);
        }
        if (testSet.size() > ans)
            ans = testSet.size();
    }
    cout << ans << endl;
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