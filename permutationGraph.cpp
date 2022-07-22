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

vi perm;
map<int, int> valToIndex;
vi preMin;
vi preMax;
vi sufMin;
vi sufMax;

int minPath(int start, int end) // goes from perm[start] to perm[end]
{
    if (start == end)
        return 0;
    if (start == end - 1)
        return 1;
    int curMin;
    int curMax;
    if (start == 0)
    {
        curMin = preMin[end];
        curMax = preMax[end];
    }
    else
    {
        curMin = sufMin[start];
        curMax = sufMax[start];
    }

    // for (int i = start; i <= end; i++)
    // {
    //     curMin = min(curMin, perm[i]);
    //     curMax = max(curMax, perm[i]);
    // }
    int minIndex = min(valToIndex[curMin], valToIndex[curMax]);
    int maxIndex = max(valToIndex[curMin], valToIndex[curMax]);
    return (minPath(start, minIndex) + 1 + minPath(maxIndex, end));
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++)
        {
            int a;
            cin >> a;
            a--;
            if (j != 0)
            {
                preMin.push_back(min(preMin[j - 1], a));
                preMax.push_back(max(preMax[j - 1], a));
            }
            else
            {
                preMin.push_back(a);
                preMax.push_back(a);
            }
            perm.push_back(a);
            valToIndex[a] = j;
        }
        sufMax.resize(s);
        sufMin.resize(s);
        sufMax[s - 1] = perm[s - 1];
        sufMin[s - 1] = perm[s - 1];
        for (int i = s - 2; i >= 0; i--)
        {
            sufMax[i] = max(sufMax[i + 1], perm[i]);
            sufMin[i] = min(sufMin[i + 1], perm[i]);
        }
        cout << minPath(0, s - 1) << endl;
        perm.clear();
        valToIndex.clear();
        sufMax.clear();
        sufMin.clear();
        preMax.clear();
        preMin.clear();
    }
    return 0;
}