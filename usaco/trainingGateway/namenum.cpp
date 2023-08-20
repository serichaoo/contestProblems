/*
ID: sericha1
TASK: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char letterToNumber(char letter)
{
	switch (letter)
	{
	case 'A':
	case 'B':
	case 'C':
		return '2';
	case 'D':
	case 'E':
	case 'F':
		return '3';
	case 'G':
	case 'H':
	case 'I':
		return '4';
	case 'J':
	case 'K':
	case 'L':
		return '5';
	case 'M':
	case 'N':
	case 'O':
		return '6';
	case 'P':
	case 'R':
	case 'S':
		return '7';
	case 'T':
	case 'U':
	case 'V':
		return '8';
	case 'W':
	case 'X':
	case 'Y':
		return '9';
	default:
		return ' ';
	}
}

bool nameMatchesNum(string name, string number)
{
	if (number.length() != name.length()) return false;
	for (int i = 0; i < name.length(); i++)
	{
		if (number[i] != letterToNumber(name[i])) return false;
	}
	return true;
}

int main()
{
	ofstream fout("namenum.out");
	ifstream fin("namenum.in");
	ifstream finDict("dict.txt");

	//ostream& fout = cout;
	//istream& fin = cin;

	string number;
	fin >> number;

	vector<string> names;
	string placeholder;
	while (finDict >> placeholder) names.push_back(placeholder);
	vector<string> possibleNames;

	for (int i = 0; i < names.size(); i++)
		if (nameMatchesNum(names[i], number)) possibleNames.push_back(names[i]);

	if (possibleNames.size() > 0)
	{
		sort(possibleNames.begin(), possibleNames.end());
		for (int i = 0; i < possibleNames.size(); i++)
			fout << possibleNames[i] << endl;
	}
	else
		fout << "NONE" << endl;

	return 0;
}
