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

struct movie
{
    ll start;
    ll end;
    bool operator<(movie a) { return end < a.end; }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<movie> movies;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        movies.push_back({a, b});
    }
    sort(all(movies));

    multiset<ll> memberCurTimes;
    for (int i = 0; i < k; i++)
        memberCurTimes.insert(0);

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (movies[i].start >= *(memberCurTimes.begin()))
        {
            ans++;
            memberCurTimes.erase(--(memberCurTimes.upper_bound(movies[i].start)));
            memberCurTimes.insert(movies[i].end);
        }
    }
    cout << ans;
    return 0;
}