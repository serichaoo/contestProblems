#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<int> heights;
	vector<int> lengths;
	int nFences;
	cin >> nFences;
	for (int i = 0; i < nFences + 1; i++)
	{
		int height;
		cin >> height;
		heights.push_back(height);
	}
	for (int i = 0; i < nFences; i++)
	{
		int length;
		cin >> length;
		lengths.push_back(length);
	}
	int answer = 0;
	for (int i = 0; i < nFences; i++)
	{
		answer += (lengths[i] * (heights[i] + heights[i + 1]));
	}
	cout << answer / 2;
	if (answer % 2 == 1)
		cout << ".5";
	return 0;
}
