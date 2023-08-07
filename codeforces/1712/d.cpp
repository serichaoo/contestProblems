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

struct value
{
    ll val;
    ll index;
};
inline bool operator<(value a, value b)
{
    if (a.val != b.val)
        return a.val < b.val;
    else
        return a.index < b.index;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vll ints(n);
    set<value> sortedInts;
    ll curMin = INF;
    for (int i = 0; i < n; i++)
    {
        cin >> ints[i];
        sortedInts.insert({ints[i], i});
        if (ints[i] < curMin)
            curMin = ints[i];
    }
    ll maxIndex = 0;
    ll maxVal = min(ints[0], ints[1]);
    for (int i = 1; i < n - 1; i++)
    {
        if (min(ints[i], ints[i + 1]) > maxVal)
        {
            maxIndex = i;
            maxVal = min(ints[i], ints[i + 1]);
        }
    }
    for (int i = 0; i < k; i++)
    {
        // if (curMin * 2 <= maxVal)
        {
            value minVal = (*(sortedInts.begin()));
            minVal.val = INF;
            ints[minVal.index] = INF;
            sortedInts.erase(sortedInts.begin());
            sortedInts.insert(minVal);
            curMin = (*sortedInts.begin()).val;
            maxVal = min(ints[maxIndex], ints[maxIndex + 1]);
            if (minVal.index > 0)
            {
                if (min(ints[minVal.index - 1], ints[minVal.index]) > maxVal)
                {
                    maxVal = min(ints[minVal.index - 1], ints[minVal.index]);
                    maxIndex = minVal.index - 1;
                }
            }
            if (min(ints[minVal.index], ints[minVal.index + 1]) > maxVal)
            {
                maxVal = min(ints[minVal.index], ints[minVal.index + 1]);
                maxIndex = minVal.index;
            }
        }
        // else
        // {
        //     if (maxVal != INF)
        //     {
        //         int minIndexFromMax;
        //         if (ints[maxIndex] == min(ints[maxIndex], ints[maxIndex + 1]))
        //             minIndexFromMax = maxIndex;
        //         else
        //             minIndexFromMax = maxIndex + 1;
        //         ints[minIndexFromMax] = INF;
        //         maxVal = min(ints[maxIndex], ints[maxIndex + 1]);
        //         if (minIndexFromMax > 0)
        //         {
        //             if (min(ints[minIndexFromMax - 1], ints[minIndexFromMax]) > maxVal)
        //             {
        //                 maxVal = min(ints[minIndexFromMax - 1], ints[minIndexFromMax]);
        //                 maxIndex = minIndexFromMax - 1;
        //             }
        //         }
        //         if (minIndexFromMax < n - 1)
        //             if (min(ints[minIndexFromMax], ints[minIndexFromMax + 1]) > maxVal)
        //             {
        //                 maxVal = min(ints[minIndexFromMax], ints[minIndexFromMax + 1]);
        //                 maxIndex = minIndexFromMax;
        //             }
        //         sortedInts.clear();
        //         for (int i = 0; i < n; i++)
        //         {
        //             sortedInts.insert({ints[i], i});
        //         }
        //         curMin = (*sortedInts.begin()).val;
        //     }
        // }
    }
    cout << min(2 * curMin, maxVal) << endl;
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