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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vi elements(n);
        vi maxIndeces = {0};
        for (int j = 0; j < n; j++)
        {
            cin >> elements[j];
            if (j != 0)
            {
                if (elements[j] > elements[maxIndeces[0]])
                {
                    maxIndeces.clear();
                    maxIndeces.push_back(j);
                }
                else if (elements[j] == elements[maxIndeces[0]])
                {
                    maxIndeces.push_back(j);
                }
            }
        }
        sort(all(maxIndeces));
        if (maxIndeces[0] + sza(maxIndeces) - 1 != maxIndeces[sza(maxIndeces) - 1])
        {
            cout << "NO" << endl;
            continue;
        }
        bool pl = true;
        for (int j = 0; j < maxIndeces[0]; j++)
        {
            if (pl)
                if (elements[j + 1] < elements[j])
                    pl = false;
        }
        for (int j = maxIndeces[sza(maxIndeces) - 1]; j < n - 1; j++)
        {
            if (pl)
                if (elements[j + 1] > elements[j])
                    pl = false;
        }
        if (pl)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}