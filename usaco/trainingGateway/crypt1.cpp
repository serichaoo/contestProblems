/*
ID: sericha1
TASK: crypt1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isIn(string number, char availableDigits[], int numAvailableDigits)
{
	bool placeholder;
	for (int i = 0; i < number.length(); i++)
	{
		placeholder = false;
		for (int j = 0; j < numAvailableDigits; j++)
			if (number[i] == availableDigits[j]) placeholder = true;
		if (placeholder == false) return false;
	}
	return true;
}

bool doesFit(int threeDigitNumber, int twoDigitNumber, char availableDigits[], int numAvailableDigits)
{
	string partial1 = to_string(int(to_string(twoDigitNumber)[0] - '0') * threeDigitNumber);
	string partial2 = to_string(int(to_string(twoDigitNumber)[1] - '0') * threeDigitNumber);
	string answer = to_string(threeDigitNumber * twoDigitNumber);
	if (partial1.length() > 3 || partial2.length() > 3) return false;
	else if (isIn(partial1, availableDigits, numAvailableDigits)
		&& isIn(partial2, availableDigits, numAvailableDigits)
		&& isIn(answer, availableDigits, numAvailableDigits)) return true;
	else return false;
}

int main()
{
#ifndef TESTING
	ofstream fout("crypt1.out");
	ifstream fin("crypt1.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif

	int numAvailableDigits;
	char availableDigits[9];
	fin >> numAvailableDigits;
	for (int i = 0; i < numAvailableDigits; i++)
	{
		fin >> availableDigits[i];
	}

	int possibleTwoDigits[81];
	int possibleThreeDigits[729];

	for (int i = 0; i < numAvailableDigits; i++)
	{
		for (int j = 0; j < numAvailableDigits; j++)
		{
			possibleTwoDigits[numAvailableDigits * i + j] = 10 * (availableDigits[i] - '0') + (availableDigits[j] - '0');
			//cout << possibleTwoDigits[numAvailableDigits * i + j] << endl;
		}
	}

	for (int i = 0; i < numAvailableDigits * numAvailableDigits; i++)
	{
		for (int j = 0; j < numAvailableDigits; j++)
			possibleThreeDigits[numAvailableDigits * i + j] = 10 * possibleTwoDigits[i] + (availableDigits[j] - '0');
	}

	int total = 0;

	for (int i = 0; i < numAvailableDigits * numAvailableDigits; i++)
		for (int j = 0; j < numAvailableDigits * numAvailableDigits * numAvailableDigits; j++)
			if (doesFit(possibleThreeDigits[j], possibleTwoDigits[i], availableDigits, numAvailableDigits)) total++;

	fout << total << endl;

	return 0;
}
