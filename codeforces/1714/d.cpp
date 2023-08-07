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

bool compFirst(pii a, pii b)
{
    return a.first < b.first;
}
bool compLast(pii a, pii b)
{
    return a.last > b.last;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string str;
        cin >> str;
        vector<bool> isCovered(sza(str), false);
        int n;
        vector<string> strs(n);
        for (int j = 0; j < n; j++)
            cin >> strs[j];
        vector<pii> sbstringLocations;
        for (int j = 0; j < sza(str); j++)
        {
            for (int k = 0; i < n; k++)
            {
                if (j + sza(strs[k]) < sza(str))
                    if (strs[k] == str.substr(j, sza(strs[k])))
                    {
                        sbstringLocations.push_back({j, j + sza(strs[k])});
                        for (int x = j; x < j + sza(strs[k]))
                            isCovered[x] = true;
                    }
            }
        }
        bool pll = true;
        for (int j = 0; j < sza(str); j++)
        {
            if (!isCovered[j])
                pll = false;
        }
        if (!pll)
            cout << -1 << endl;
        else
        {
            int counter = 0;
            int curVal = 0;
            vector<pii> curPossibilities
            sort(all(sbstringLocations), 
            while (curVal != sza(str)-1)
            {

            }
        }
    }

    return 0;
}