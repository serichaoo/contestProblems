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
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

struct bound
{
    int index;
    int lo;
    int hi;
};
struct bound2
{
    int index;
    int lo;
    int hi;
};
bound2 toBound(bound a)
{
    return {a.index, a.lo, a.hi};
}
bool operator<(bound a, bound b)
{
    if (a.lo != b.lo)
        return a.lo < b.lo;
    if (a.hi != b.hi)
        return a.hi < b.hi;
    return a.index < b.index;
}
bool operator<(bound2 a, bound2 b)
{
    if (a.hi != b.hi)
        return a.hi < b.hi;
    return a.index < b.index;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int s;
        cin >> s;
        set<bound> bounds;
        for (int j = 1; j <= s; j++)
        {
            int x;
            cin >> x;
            int lo = (j + x + 1) / (x + 1);
            int hi;
            if (x != 0)
                hi = j / x;
            else
                hi = s;
            bounds.insert({j, lo, hi});
        }
        vector<int> perm(s, -1);
        int val = 1;
        auto it = bounds.begin();
        set<bound2> bounds2;
        while (val <= s)
        {
            while ((*it).lo <= val && it != bounds.end())
            {
                bounds2.insert(toBound(*it));
                it++;
            }
            perm[(*bounds2.begin()).index - 1] = val;
            bounds2.erase(bounds2.begin());
            val++;
        }
        for (int i = 0; i < s; i++)
            cout << perm[i] << ' ';
        cout << endl;
    }
    return 0;
}
