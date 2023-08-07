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

// vll primePowers;
vll lcmFirstNNumbers{1, 1};
vll primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
// vector<bool> isPrime(ll(1e18 + 1), true);
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
void solve()
{
    // ll n;
    // cin >> n;
    // ll i = 0;
    // while (i < 15)
    // {
    //     if (n % prodFirstNPrimes[i] == 0)
    //         i++;
    //     else
    //         break;
    // }
    // max length possible is primes[i-1]-1, but not necessarily possible
    // cout << primes[i - 1] - 1 << endl;
    ll n;
    cin >> n;
    for (int i = 0; i < 43; i++)
    {
        if (n % lcmFirstNNumbers[i] != 0)
        {
            cout << i - 1 << endl;
            return;
        }
        if (i == 42)
        {
            cout << 42 << endl;
        }
    }
}
int main()
{

    // // sieve, era...
    // isPrime[1] = false;
    // for (ll i = 2; i <= 1e18; i++)
    // {
    //     if (isPrime[i])
    //         for (ll j = i; i * j <= 1e18; j++)
    //             isPrime[i * j] = false;
    // }
    for (ll i = 2; i < 43; i++)
    {
        lcmFirstNNumbers.push_back(lcm(lcmFirstNNumbers[i - 1], i));
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();

    return 0;
}