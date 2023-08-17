#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;
// Function to find binomial
// coefficient
//int binomialCoeff(int n, int r)
//{
//
//	if (r > n)
//		return 0;
//	long long int m = 1000000007;
//	long long int inv[r + 1] = { 0 };
//	inv[0] = 1;
//	if (r + 1 >= 2)
//		inv[1] = 1;
//
//	// Getting the modular inversion
//	// for all the numbers
//	// from 2 to r with respect to m
//	// here m = 1000000007
//	for (int i = 2; i <= r; i++) {
//		inv[i] = m - (m / i) * inv[m % i] % m;
//	}
//
//	int ans = 1;
//
//	// for 1/(r!) part
//	for (int i = 2; i <= r; i++) {
//		ans = ((ans % m) * (inv[i] % m)) % m;
//	}
//
//	// for (n)*(n-1)*(n-2)*...*(n-r+1) part
//	for (int i = n; i >= (n - r + 1); i--) {
//		ans = ((ans % m) * (i % m)) % m;
//	}
//	return ans;
//}
vector<ll> fact(4e5 + 3, 1);
vector<ll> invFact(4e5 + 3, 1);

const int p = 1e9 + 7;

ll power(ll x, ll y)
{

	// Initialize answer
	ll res = 1;

	// Check till the number becomes zero
	while (y > 0) {

		// If y is odd, multiply x with result
		if (y % 2 == 1)
			res = (res * x) % p;

		// y = y/2
		y = y / 2;

		// Change x to x^2
		x = (x * x) % p;
	}
	return res % p;
}
ll binomCoeff(ll a, ll b)
{
	if (b > a)
		return 0;
	return (((fact[a] * invFact[b]) % p) * invFact[a - b]) % p;
}

int main()
{
	for (int i = 1; i < 4e5 + 3; i++)
	{
		fact[i] = (fact[i - 1] * i) % p;
		invFact[i] = power(fact[i], p - 2);
	}
	vector<int> vals;
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 0; i <= n; i++)
	{
		int a;
		cin >> a;
		ans += binomCoeff(i + a, i + 1);
		ans %= 1000000007;
	}
	cout << ans;
	return 0;
}
