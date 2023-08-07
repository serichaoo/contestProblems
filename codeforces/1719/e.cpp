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
const ll HIGH = 1e11 + 1;

vll fibb{1, 1};
map<ll, ll> valToIndex;

bool isPossible(const vll &elements, ll sum, ll n)
{
    bitset<HIGH> dp{1};

    for (int i = 0; i < n; i++)
    {
        for (int j = sum; j >= elements[i]; j--)
        {
            bitset placeholder = dp;
            placeholder <<= elements[i];
            dp |= placeholder;
        }
    }

    if (dp[sum] == 1)
        return true;

    return false;
}

void solve()
{
    ll k;
    cin >> k;
    vll c(k);
    ll sum = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
        sum += c[i];
    }
    if (valToIndex[sum + 1] == 0)
    {
        cout << "NO" << endl;
        return;
    }
    ll maxIndex = valToIndex[sum + 1] - 2;
    // must separate the c[i] into two sums
    // if maxIndex is odd, one sum of fibb[maxIndex] and one sum of fibb[maxIndex+1]-1
    // if maxIndex is even, one sum of fibb[maxIndex]-1 and other is fibb[maxIndex+1]
    ll targetSum;
    if (maxIndex % 2 == 1)
        targetSum = fibb[maxIndex];
    else
        targetSum = fibb[maxIndex] - 1;
    if (isPossible(c, targetSum, k))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (fibb[sza(fibb) - 1] < 1e11 + 2)
    {
        ll n = fibb[sza(fibb) - 1] + fibb[sza(fibb) - 2];
        valToIndex[n] = sza(fibb);
        fibb.push_back(n);
    }
    int t;
    cin >> t;
    // bitset<100> test{1};
    // test <<= 3;
    for (int i = 0; i < t; i++)
        solve();

    return 0;
}