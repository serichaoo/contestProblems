#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;
using vll = vector<ll>;
// solved after 40 min, 1 hour into contest
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vll vals(n);
    // vector<vll> symmDiffs(2 * n - 1, vll(0));
    vll minima(n + 1, 1e10);
    for (int i = 0; i < n; i++)
    {
        cin >> vals[i];
    }
    for (int i = 0; i < 2 * n - 1; i++) // if i is even then start on an integer, else start between ints
    {
        vll symmDiffs(0);
        int numDiffs = min(i / 2 + 1, (2 * n - i) / 2);
        if ((i % 2) == 0) // start on vals[i/2]
        {
            for (int j = 0; j < numDiffs; j++)
            {
                symmDiffs.push_back(abs(vals[i / 2 + j] - vals[i / 2 - j]));
            }
            vll prefixSum(numDiffs + 1, 0);
            for (int j = 1; j < numDiffs + 1; j++)
            {
                prefixSum[j] = prefixSum[j - 1] + symmDiffs[j - 1];
                if (prefixSum[j] < minima[2 * j - 1])
                    minima[2 * j - 1] = prefixSum[j];
            }
        }
        else
        {
            for (int j = 0; j < numDiffs; j++)
            {
                symmDiffs.push_back(abs(vals[i / 2 + j + 1] - vals[i / 2 - j]));
            }
            vll prefixSum(numDiffs + 1, 0);
            for (int j = 1; j < numDiffs + 1; j++)
            {
                prefixSum[j] = prefixSum[j - 1] + symmDiffs[j - 1];
                if (prefixSum[j] < minima[2 * j])
                    minima[2 * j] = prefixSum[j];
            }
        }
    }
    for (int i = 1; i <= n - 1; i++)
        cout << minima[i] << ' ';
    cout << minima[n];

    return 0;
}