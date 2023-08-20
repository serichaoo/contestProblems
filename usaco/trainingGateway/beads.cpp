/*
ID: sericha1
TASK: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int split(const string& beads, int startPosition, bool directionLeft)
{
	int count{ 0 };
	int currentRedCount{ 0 };
	int currentBlueCount{ 0 };
	for (int i = 0; i < beads.size(); i++)
	{
		int position = (startPosition + (directionLeft ? -i : i) + beads.size()) % beads.size();
		if (beads[position] == 'r') currentRedCount++;
		if (beads[position] == 'b') currentBlueCount++;
		if (currentRedCount && currentBlueCount) break;
		count++;
	}
	return count;
}

int main()
{
	ofstream fout("beads.out");
	ifstream fin("beads.in");

	int numberOfBeads;
	fin >> numberOfBeads;
	string beads;
	fin >> beads;
	int maximum{ 0 };

	maximum = split(beads, numberOfBeads - 1, true) + split(beads, 0, false);
	for (int i = 1; i < numberOfBeads; i++)
	{
		int value = split(beads, i - 1, true) + split(beads, i, false);
		if (value > maximum) maximum = value;
	}

	if (maximum > numberOfBeads) maximum = numberOfBeads;
	fout << maximum << endl;

	return 0;
}






/*int numberOfBeads{};
//int numberOfSplits{ 0 };

char findPreviousColour(int position, string beads, int numberOfBeads)
{
	for (int i = 1; i <= numberOfBeads; i++)
	{
		if (position - i < 0) position += numberOfBeads;
		if (beads[position - i] != 'w') return beads[position - i];
	}
	return -1;
}

char findNextColour(int position, string beads, int numberOfBeads)
{
	for (int i = 1; i <= numberOfBeads; i++)
	{
		if (position + i >= numberOfBeads) position -= numberOfBeads;
		if (beads[position + i] != 'w') return beads[position + i];
	}
	return -1;
}

int findPreviousColourPosition(int position, string beads, int numberOfBeads, char colour)
{
	for (int i = 1; i <= numberOfBeads; i++)
	{
		if (position - i < 0) position += numberOfBeads;
		if (beads[position - i] == colour) return (position - i);
	}
	return -1;
}


int findNextColourPosition(int position, string beads, int numberOfBeads, char colour)
{
	for (int i = 1; i <= numberOfBeads; i++)
	{
		if (position + i >= numberOfBeads) position -= numberOfBeads;
		if (beads[position + i] == colour) return (position + i);
	}
	return -1;
}

int stringToMaximum(string beads, int numberOfBeads)
// No whites allowed in this function
{
	int numConsecutiveColours[350]{};
	int index{ 0 };
	char currentColourTemp{ beads[0] };
	int maximumTemp{ 0 };
	for (int i = 0; i < numberOfBeads;)
	{
		if (currentColourTemp == 'r')
		{
			numConsecutiveColours[index] = (findNextColourPosition(i, beads, numberOfBeads, 'b')
				- findPreviousColourPosition(i, beads, numberOfBeads, 'b')
				+ numberOfBeads) % numberOfBeads;
			i = findNextColourPosition(i, beads, numberOfBeads, 'b');
			index++;
		}
		else
		{
			numConsecutiveColours[index] = (findNextColourPosition(i, beads, numberOfBeads, 'r')
				- findPreviousColourPosition(i, beads, numberOfBeads, 'r')
				+ numberOfBeads) % numberOfBeads;
			i = findNextColourPosition(i, beads, numberOfBeads, 'r');
			index++;
		}
	}
	for (int i = 0; i < index - 1; i++)
	{
		if (numConsecutiveColours[i] + numConsecutiveColours[i + 1] > maximumTemp)
			maximumTemp = numConsecutiveColours[i] + numConsecutiveColours[i + 1];
	}
	if (numConsecutiveColours[0] + numConsecutiveColours[index] > maximumTemp)
		maximumTemp = numConsecutiveColours[0] + numConsecutiveColours[index];
}

string removeWhiteAlternate(string beads, int numberOfBeads)
{
	char newBeads[350]{};
	int numberOfReplacements{ 0 };
	while (findNextColourPosition(0, beads, numberOfBeads, 'w') != -1)
	{

	}
}
/*int splitToBeads(int position, string beads, int numberOfBeads)
{
	numberOfSplits++;
	return (((findNextColourPosition(position, beads, numberOfBeads, findPreviousColour(position, beads, numberOfBeads))
		- findPreviousColourPosition(position, beads, numberOfBeads, beads[position]) - 1)
		+ numberOfBeads) % numberOfBeads);
}
*/
/*int main()
{
	ofstream fout("beads.out");
	ifstream fin("beads.in");

	cin >> numberOfBeads;
	string beads;
	cin >> beads;
	// Create an array of splits at the locations
	// A split at position 0 means the split is behind the 0th bead
	int maximum{ 0 };

	for (int i = 0; i < numberOfBeads; i++)
	{
		if (beads[i] == 'r')
		{
			if (findPreviousColour(i, beads, numberOfBeads) == 'b')
			{
				//cout << i << ' ' << splitToBeads(i, beads, numberOfBeads) << endl;
				if (maximum < splitToBeads(i, beads, numberOfBeads)) maximum = splitToBeads(i, beads, numberOfBeads);
			}
		}
		if (beads[i] == 'b')
		{
			if (findPreviousColour(i, beads, numberOfBeads) == 'r')
			{
				//cout << i << ' ' << splitToBeads(i, beads, numberOfBeads) << endl;
				if (maximum < splitToBeads(i, beads, numberOfBeads)) maximum = splitToBeads(i, beads, numberOfBeads);
			}
		}
	}

	cout << numberOfSplits;
	if (numberOfSplits != 0 && numberOfSplits != 2) cout << maximum << endl;
	else cout << numberOfBeads << endl;

	return 0;
}


int main()
{
	ofstream fout("beads.out");
	ifstream fin("beads.in");

	cin >> numberOfBeads;
	string beads;
	cin >> beads;

	char updatedBeads[350]{};
	if (findNextColourPosition(0, beads, numberOfBeads, 'r') == -1 || findNextColourPosition(0, beads, numberOfBeads, 'b') == -1)
		return numberOfBeads;
	for (int i = 0; i < numberOfBeads; i++)
	{
		if (findPreviousColour(i, beads, numberOfBeads) == findNextColour(i, beads, numberOfBeads))
			updatedBeads[i] = findPreviousColour(i, beads, numberOfBeads);
		else
			updatedBeads[i] = beads[i];
	}
	char currentColour{ updatedBeads[0] };
	if (findNextColourPosition(0, updatedBeads, numberOfBeads, 'w') == -1)
		return stringToMaximum(updatedBeads, numberOfBeads);

	char beadsCopy[350]{};


}
*/