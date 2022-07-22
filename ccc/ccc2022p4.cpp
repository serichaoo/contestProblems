#include <iostream>
#include <vector>
#include <string>

using namespace std;

int mod(int a, int b)
{
	return (a + b) % b;
}

int main()
{
	int n, c;
	cin >> n >> c;
	if (n < 201)
	{
		int ans = 0;
		vector<int> allLocations(n);
		for (int i = 0; i < n; i++)
			cin >> allLocations[i];
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				for (int k = j + 1; k < j; k++)
				{
					if ((allLocations[k] - ((allLocations[i] + c / 2) % c) > 0 && ((allLocations[j] - (allLocations[i] + c / 2) % c)) < 0) || (allLocations[j] - ((allLocations[i] + c / 2) % c) > 0 && ((allLocations[k] - (allLocations[i] + c / 2) % c)) < 0))
						if ((allLocations[i] - ((allLocations[j] + c / 2) % c) > 0 && ((allLocations[k] - (allLocations[j] + c / 2) % c)) < 0) || (allLocations[k] - ((allLocations[j] + c / 2) % c) > 0 && ((allLocations[i] - (allLocations[j] + c / 2) % c)) < 0))
							if ((allLocations[j] - ((allLocations[k] + c / 2) % c) > 0 && ((allLocations[i] - (allLocations[k] + c / 2) % c)) < 0) || (allLocations[i] - ((allLocations[k] + c / 2) % c) > 0 && ((allLocations[j] - (allLocations[k] + c / 2) % c)) < 0))
								ans++;
				}
		cout << ans;
		return 0;
	}

	//vector<int> nDrawnPoints(2 * circumference, 0); // tells you how many points are at that specific point on the circle
	//for (int i = 0; i < nPoints; i++)
	//{
	//	int a;
	//	cin >> a;
	//	nDrawnPoints[a]++;
	//}
	//for (int i = circumference; i < 2 * circumference; i++)
	//	nDrawnPoints[i] = nDrawnPoints[i - circumference];
	//long long ans = 0;
	//long long currentUpperStoredValue = 0;
	//long long currentLowerStoredValue = 0;
	//for (int i = circumference / 4 + 1; i < (circumference + 1) / 2; i++)
	//	currentUpperStoredValue += nDrawnPoints[i];

	//int lowerBound = circumference / 4 + 1;
	//int upperLowerBound = (circumference + 1) / 2;
	//int lowerUpperBound = (circumference) / 2 + 1;
	//int upperBound = circumference - circumference / 4;
	//for (int i = lowerUpperBound; i < upperBound; i++)
	//	currentLowerStoredValue += nDrawnPoints[i];

	//for (int i = 0; i < circumference; i++)
	//{
	//	ans += nDrawnPoints[i] * currentUpperStoredValue * currentLowerStoredValue;
	//	currentUpperStoredValue += (nDrawnPoints[upperLowerBound] - nDrawnPoints[lowerBound]);
	//	currentLowerStoredValue += (nDrawnPoints[upperBound] - nDrawnPoints[lowerUpperBound]);
	//	lowerBound++;
	//	upperBound++;
	//	upperLowerBound++;
	//	lowerUpperBound++;
	//}
	//cout << ans / 2;

}