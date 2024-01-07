#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool isIn(const vector<char>& element, const  vector<vector<char>>& list)
{
	for (int i = 0; i < list.size(); i++)
		if (element[0] == list[i][0] && element[1] == list[i][1] && element[2] == list[i][2])
			return true;
	return false;
}

int strToIndex(string str) // always 3 characters long
{
	int value = 0;
	value += (str[0] - '0');
	value += (str[1] - '0') * 4;
	value += (str[2] - '0') * 16;
	return value;
}

int main()
{
#ifndef TESTING
	ofstream fout("cownomics.out");
	ifstream fin("cownomics.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif

	int numPlainCows, length;
	fin >> numPlainCows >> length;

	vector<string> plainCows, spottedCows;
	for (int i = 0; i < numPlainCows; i++)
	{
		string placeholder;
		fin >> placeholder;
		string placeholder1;
		for (int i = 0; i < length; i++)
		{
			if (placeholder[i] == 'A')
				placeholder1.push_back('0');
			else if (placeholder[i] == 'T')
				placeholder1.push_back('1');
			else if (placeholder[i] == 'C')
				placeholder1.push_back('2');
			else if (placeholder[i] == 'G')
				placeholder1.push_back('3');
		}
		spottedCows.push_back(placeholder1);
	}
	for (int i = 0; i < numPlainCows; i++)
	{
		string placeholder;
		fin >> placeholder;
		string placeholder1;
		for (int i = 0; i < length; i++)
		{
			if (placeholder[i] == 'A')
				placeholder1.push_back('0');
			else if (placeholder[i] == 'T')
				placeholder1.push_back('1');
			else if (placeholder[i] == 'C')
				placeholder1.push_back('2');
			else if (placeholder[i] == 'G')
				placeholder1.push_back('3');
		}
		plainCows.push_back(placeholder1);
	}

	int count = 0;

	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			for (int k = j + 1; k < length; k++)
			{
				bool isPlainArrangement[64]{ 0 };
				for (int x = 0; x < numPlainCows; x++)
				{
					string placeholder;
					placeholder.push_back(plainCows[x][i]);
					placeholder.push_back(plainCows[x][j]);
					placeholder.push_back(plainCows[x][k]);
					isPlainArrangement[strToIndex(placeholder)] = true;
				}
				bool isCons = true;
				for (int x = 0; x < numPlainCows; x++)
				{
					string placeholder;
					placeholder.push_back(spottedCows[x][i]);
					placeholder.push_back(spottedCows[x][j]);
					placeholder.push_back(spottedCows[x][k]);

					if (isPlainArrangement[strToIndex(placeholder)])
						isCons = false;
				}
				if (isCons) count++;
			}
		}
	}
	fout << count;

	return 0;
}