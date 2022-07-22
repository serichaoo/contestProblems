#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct element
{
	int index;
	int value;
};

bool compValues(element a, element b)
{
	return a.value < b.value;
}

int main()
{
	int n, x;
	cin >> n >> x;
	vector<element> elements;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		elements.push_back({ i,a });
	}
	sort(elements.begin(), elements.end(), compValues);
	int pointer1 = 0;
	int pointer2 = n - 1;
	int currentValue;
	while ((elements[pointer1].value + elements[pointer2].value != x) && pointer1 != pointer2)
	{
		currentValue = elements[pointer1].value + elements[pointer2].value;
		if (currentValue < x)
			pointer1++;
		else
			pointer2--;
	}
	if (pointer1 == pointer2)
		cout << "IMPOSSIBLE";
	else
		cout << elements[pointer1].index + 1 << ' ' << elements[pointer2].index + 1;
	return 0;
}
