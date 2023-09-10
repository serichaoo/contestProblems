#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back;

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

map<ll, pair<ll, ll>> pow2Diff;
map<ll, ll> log2PlusOne;
// try to do the method of d1 if necessary. if the desired difference is a power of 2,
// figure out whether to do a single give/receive or the double give/receive after doing all
// necessary operations, and then do greedy to reduce the sum abs(check[i]).
void solve()
{
    int n;
    cin >> n;
    vll nums(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    if (sum % n != 0)
    {
        cout << "NO" << endl;
        return;
    }
    ll avg = sum / n;
    vll desiredDiff(n);
    for (int i = 0; i < n; i++)
        desiredDiff[i] = avg - nums[i];

    vll check(34, 0);
    vll pows2(33, 0);
    for (int i = 0; i < n; i++)
    {
        if (desiredDiff[i] != 0)
        {
            if (log2PlusOne[abs(desiredDiff[i])] != 0)
            {
                if (desiredDiff[i] > 0)
                    pows2[log2PlusOne[desiredDiff[i]] - 1]++;
                else
                    pows2[log2PlusOne[abs(desiredDiff[i])] - 1]--;
                continue;
            }
            if (pow2Diff[desiredDiff[i]].first == 0 && pow2Diff[desiredDiff[i]].second == 0)
            {
                cout << "NO" << endl;
                return;
            }
            ll a = pow2Diff[desiredDiff[i]].first;
            ll b = pow2Diff[desiredDiff[i]].second;
            check[a]++;
            check[b]--;
        }
    }
    for (int i = 0; i < 33; i++)
        if (pows2[i] != 0)
        {
            pows2[i] -= check[i];
            check[i] = 0;
            if (pows2[i] % 2 != 0)
            {
                cout << "NO" << endl;
                return;
            }

            check[i + 1] += pows2[i] / 2;
        }

    for (int i = 0; i < 34; i++)
    {
        if (check[i] != 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = 0; i < 33; i++)
    {
        if (pows2[i] != 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vll pows2{1};
    ll initial = 1;
    log2PlusOne[1] = 1;
    for (int i = 1; i < 33; i++)
    {
        pows2.push_back(initial * 2);
        initial *= 2;
        log2PlusOne[initial] = i + 1;
    }
    for (int i = 0; i < 33; i++)
        for (int j = 0; j < 33; j++)
        {
            if (i != j)
            {
                pow2Diff[pows2[i] - pows2[j]] = {i, j};
            }
        }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();

    return 0;
}