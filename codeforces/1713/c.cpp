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

map<int, vi> permutations;
vi curAns;

int floorSqrt(int x)
{
    // Base cases
    if (x == 0 || x == 1)
        return x;

    // Do Binary Search for floor(sqrt(x))
    int start = 1, end = x / 2, ans;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int sqr = mid * mid;
        if (sqr == x)
            return mid;
        if (sqr <= x)
        {
            start = mid + 1;
            ans = mid;
        }
        else
            end = mid - 1;
    }
    return ans;
}

vi solve(int x)
{
    if (sza(permutations[x]) > 0)
        return permutations[x];
    vi ans(x);
    int sqrt = floorSqrt(x - 2);
    int upperSquare = (sqrt + 1) * (sqrt + 1);
    int index = upperSquare - (x - 1);
    for (int i = index; i < x; i++)
    {
        ans[i] = upperSquare - i;
    }
    if (index > 0)
    {
        vi firstIndeces = solve(index);
        for (int i = 0; i < index; i++)
            ans[i] = firstIndeces[i];
    }
    permutations[x] = ans;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x = 0;
    while (x * x <= 1e5)
    {
        vi perm(x * x + 1);
        for (int i = 0; i < x * x + 1; i++)
            perm[i] = x * x - i;
        permutations[x * x + 1] = perm;
        x++;
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int p;
        cin >> p;
        vi sol = solve(p);
        for (int i = 0; i < p - 1; i++)
            cout << sol[i] << ' ';
        cout << sol[p - 1] << endl;
    }

    return 0;
}