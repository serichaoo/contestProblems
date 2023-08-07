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

bool getNBit(ll num, ll pos)
{
    return ((num >> pos) % 2);
}

int ipow(int base, int exp)
{
    int result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    vll b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    ll ans = 0;
    vll bGroup(n);
    ll maxGroupVal = 0;
    vll numEachBitA(30);
    vll numEachBitB(30);
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (getNBit(a[j], i))
                numEachBitA[i]++;
            if (getNBit(b[j], i))
                numEachBitB[i]++;
        }
    }
    for (int i = 29; i >= 0; i--)
    {
        if (numEachBitA[i] + numEachBitB[i] == n)
        {
            ll offVal = -1;
            ll onVal = -1;
            bool placeholder = true;
            vll offVals;
            vll onVals;
            for (int i = 0; i < n; i++)
            {
                if (getNBit(b[i], i))
                {
                    onVals.push_back(i);
                }
                else
                    offVals.push_back(i);
            }
            for (int i = 0; i < onVals.size() - 1; i++)
                if (bGroup[onVals[i + 1]] != bGroup[onVals[i]])
                    placeholder = false;
            // for (int i = 0; i < offVals.size() - 1; i++)
            //     if (bGroup[offVals[i + 1]] != bGroup[offVals[i]])
            //         placeholder = false;
            if (placeholder)
            {
                ans += ipow(2, i);
                for (int i = 0; i < onVals.size(); i++)
                    bGroup[onVals[i]] = maxGroupVal + 1;

                maxGroupVal += 1;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    // for (int i = 0; i < 7; i++)
    //     cout << getNBit(100, 7 - i);
    for (int i = 0; i < t; i++)
        solve();

    return 0;
}