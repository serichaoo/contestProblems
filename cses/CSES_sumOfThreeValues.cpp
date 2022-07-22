#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct element
{
	int index;
	int value;
};

bool compElements(element a, element b)
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
	sort(elements.begin(), elements.end(), compElements);

	for (int i = 0; i < n; i++)
	{
		int leftPointer = 0;
		int rightPointer = n - 1;
		while (leftPointer != i && rightPointer != i)
		{
			int currentValue = elements[leftPointer].value
				+ elements[i].value + elements[rightPointer].value;
			if (currentValue < x)
				leftPointer++;
			else if (currentValue > x)
				rightPointer--;
			else if (currentValue == x)
			{
				cout << elements[leftPointer].index + 1
					<< ' ' << elements[i].index + 1
					<< ' ' << elements[rightPointer].index + 1;
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}

