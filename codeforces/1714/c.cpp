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

int exp(int base, int expo)
{
    if (expo == 0)
        return 1;
    else
        return base * exp(base, expo - 1);
}

int minN(int s)
{
    int pl = 9;
    vector<int> nums;
    while (s >= pl && s > 0)
    {
        nums.push_back(pl);
        s -= pl;
        pl--;
    }
    if (s > 0)
        nums.push_back(s);
    int ans = 0;
    for (int i = 0; i < sza(nums); i++)
        ans += exp(10, i) * nums[i];
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int s;
        cin >> s;
        cout << minN(s) << endl;
    }
    return 0;
}