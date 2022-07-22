#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<ll> fact(1e6 + 2, 1);
vector<ll> invFact(1e6 + 2, 1);

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

int main()
{
	for (int i = 1; i < 1e6 + 2; i++)
	{
		fact[i] = (fact[i - 1] * i) % p;
		invFact[i] = power(fact[i], p - 2);
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << (((fact[a] * invFact[b]) % p) * invFact[a - b]) % p << endl;
	}
	return 0;
}
