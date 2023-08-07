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

vector<bool> subset1{0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0};
vector<bool> subset2{0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1};

bool checkIfSubset(vi ints)
{
    bool pl1 = true;
    bool pl2 = true;
    for (int i = 0; i < sza(ints); i++)
    {
        if (!subset1[ints[i]])
            pl1 = false;
        if (!subset2[ints[i]])
            pl2 = false;
    }
    return (pl1 || pl2);
}

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
        vi ints(n);
        vi mod20(n);
        bool allDiv5 = true;
        for (int j = 0; j < n; j++)
        {
            cin >> ints[j];
            mod20[j] = ints[j] % 20;
            if ((ints[j] % 5) != 0)
                allDiv5 = false;
        }
        if (checkIfSubset(mod20))
        {
            cout << "yes" << endl;
        }
        else if (allDiv5)
        {
            set<int> allInts;
            for (int j = 0; j < n; j++)
            {
                if ((ints[j] % 10) == 5)
                    allInts.insert(ints[j] + 5);
                else
                    allInts.insert(ints[j]);
            }
            if (sza(allInts) == 1)
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
        else
            cout << "no" << endl;
    }
    return 0;
}