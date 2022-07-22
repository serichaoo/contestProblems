#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n % 5 != 0)
		n -= 4;
	while (n % 20 != 0)
		n -= 5;
	n /= 20;
	if (n < 0)
	{
		cout << 0;
		return 0;
	}
	cout << n + 1;
	return 0;
}