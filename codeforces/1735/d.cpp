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

vector<vi> cards;
int n, k;
vector<vi> sets;

bool comp(int x, int y, int z)
{
    return (x == y == z || (x != y && y != z && z != x));
}

bool isSet(int a, int b, int c)
{
    for (int i = 0; i < k; i++)
        if (!comp(cards[a][k], cards[b][k], cards[c][k]))
            return false;
    return true;
}

ll numMetaSetsWithNSets(int n)
{
    vi vars(n);
    for (int i = 0; i < n; i++)
        vars[i] = i;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    cards.resize(n, vi(k));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            cin >> cards[i][j];

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if (isSet(i, j, k))
                    sets.push_back({i, j, k});

    return 0;
}