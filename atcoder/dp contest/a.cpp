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

int main()
{
    int N;
    cin >> N;
    vi heights(N);
    for (int i = 0; i < N; i++)
    {
        cin >> heights[i];
    }
    vi minCost(N + 2, INF);
    minCost[0] = 0;
    for (int i = 0; i < N; i++)
    {
        if (i + 1 < N)
            minCost[i + 1] = min(minCost[i + 1], minCost[i] + abs(heights[i + 1] - heights[i]));
        if (i + 2 < N)
            minCost[i + 2] = min(minCost[i + 2], minCost[i] + abs(heights[i + 2] - heights[i]));
    }
    cout << minCost[N - 1];
    return 0;
}