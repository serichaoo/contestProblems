#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> constructPermutations(vector<int> currentPermutation, int newItem)
{
	vector<vector<int>> permutations;

	for (int i = 0; i < currentPermutation.size() + 1; i++)
	{
		vector<int> placeholder = currentPermutation;
		placeholder.insert(placeholder.begin() + i, newItem);
		permutations.push_back(placeholder);
	}
	return permutations;
}

vector<vector<int>> constructAllPermutations(int n)
{
	vector<vector<int>> allPermutations;
	if (n == 1)
	{
		vector<int> placeholder;
		placeholder.push_back(1);
		allPermutations.push_back(placeholder);
		return allPermutations;
	}
	vector<vector<int>> allSmallerPermutations;
	allSmallerPermutations = constructAllPermutations(n - 1);
	for (int i = 0; i < allSmallerPermutations.size(); i++)
	{
		vector<vector<int>> placeholder = constructPermutations(allSmallerPermutations[i], n);
		allPermutations.insert(allPermutations.end(), placeholder.begin(), placeholder.end());
	}
	return allPermutations;
}

void printPermutation(const vector<int>& currentPermutation) {
	for (int i = 0; i < currentPermutation.size(); ++i) cout << currentPermutation[i] << " ";
	cout << endl;
}

void printPermutations(vector<int> currentPermutation, int newItem, int finalItem)
{
	if (newItem > finalItem) printPermutation(currentPermutation);
	else {
		for (int i = 0; i < currentPermutation.size() + 1; i++)
		{
			vector<int> placeholder = currentPermutation;
			placeholder.insert(placeholder.begin() + i, newItem);
			printPermutations(placeholder, newItem + 1, finalItem);
		}
	}
}

void printAllPermutations(int n)
{
	printPermutations({}, 1, n);
}

void printPermutationsWithPrefix(vector<int> partialPermutation, vector<int> remainingNumbersToUse) {
	if (remainingNumbersToUse.size() == 0) printPermutation(partialPermutation);
	for (int i = 0; i < remainingNumbersToUse.size(); ++i) {
		vector<int> newPartialPermutation = partialPermutation;
		newPartialPermutation.push_back(remainingNumbersToUse[i]);
		vector<int> newRemainingNumbers = remainingNumbersToUse;
		newRemainingNumbers.erase(newRemainingNumbers.begin() + i);
		printPermutationsWithPrefix(newPartialPermutation, newRemainingNumbers);
	}
}

vector<int> oneToN(int n) {
	vector<int> v;
	for (int i = 0; i < n; ++i) v.push_back(i);
	return v;
}

void printAllPermutations2(int n) {
	printPermutationsWithPrefix({}, oneToN(n));
}

int main()
{
	int n;
	cin >> n;
	printAllPermutations(n); return 0;
	vector<vector<int>> permutationsOfN = constructAllPermutations(n);
	for (int i = 0; i < permutationsOfN.size(); i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << permutationsOfN[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
