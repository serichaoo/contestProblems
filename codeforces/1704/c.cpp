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

int remainingLength(int length, int index)
{
    int curLength = length - 4 * index;
    if (curLength >= 2)
        return curLength - 1;
    if (curLength == 1)
        return 1;
    else
        return 0;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        vi infected;
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            infected.push_back(a);
        }
        sort(all(infected));
        vi lengths;
        for (int j = 0; j < m - 1; j++)
        {
            lengths.push_back(infected[j + 1] - infected[j] - 1);
        }
        lengths.push_back(infected[0] + n - infected[m - 1] - 1);
        sort(all(lengths));
        reverse(all(lengths));
        int ans = 0;
        for (int i = 0; i < sza(lengths); i++)
        {
            ans += remainingLength(lengths[i], i);
        }
        cout << n - ans << endl;
    }
    return 0;
}