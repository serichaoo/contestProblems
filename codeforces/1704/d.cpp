#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

using ld = long double;
using ll = long long;
using ull = unsigned long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int main()
{
    int t;
    cin >> t;
    for (int p = 0; p < t; p++)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<ull>> a;
        vector<ull> vals;
        for (int j = 0; j < n; j++)
        {
            vector<ull> b(m);
            ull bVal = 0;
            for (int k = 0; k < m; k++)
            {
                cin >> b[k];
                bVal += (k + 1) * b[k];
            }
            vals.push_back(bVal);
            a.push_back(b);
        }
        map<int, bool> isChecked;
        ull regVal;
        int index;
        for (int i = 0; i < n; i++)
        {
            if (isChecked[vals[i]])
            {
                regVal = vals[i];
                break;
            }
            else
                isChecked[vals[i]] = true;
        }
        for (int i = 0; i < n; i++)
        {
            if (vals[i] != regVal)
                index = i;
        }
        cout << index + 1 << ' ' << vals[index] - regVal << endl;
    }

    return 0;
}