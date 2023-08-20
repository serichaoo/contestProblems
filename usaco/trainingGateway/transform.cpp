/*
ID: sericha1
TASK: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void reflect(char* fixedPattern, char* pattern, int pSize)
{ // reflection replaces pattern[i][j] (size*i + j) with pattern[i][size-1-j] (size*i + size-1-j)
	for (int a = 0; a < pSize * pSize; a++)
	{
		int i = a / pSize;
		int j = a % pSize;
		pattern[pSize * i + pSize - 1 - j] = fixedPattern[pSize * i + j];
	}
}

void rotate90(char* fixedPattern, char* pattern, int pSize)
{ // rotation of 90 degrees replaces pattern[i][j] (size*i + j) with pattern[j][size-1-i] (size*j+size-1-i)
	for (int a = 0; a < pSize * pSize; a++)
	{
		int i = a / pSize;
		int j = a % pSize;
		pattern[pSize * j + pSize - 1 - i] = fixedPattern[pSize * i + j];
	}
}

bool comparePatterns(char* pattern1, char* pattern2, int pSize)
{
	for (int i = 0; i < pSize * pSize; i++)
		if (pattern1[i] != pattern2[i]) return false;
	return true;
}



int main()
{
	ofstream fout("transform.out");
	ifstream fin("transform.in");

	//istream& fin = cin;
	//ostream& fout = cout;

	int pSize;
	char pattern[100]{};
	char patternRotated90[100]{};
	char patternRotated180[100]{};
	char patternRotated270[100]{};
	char patternReflectedR90[100]{};
	char patternReflectedR180[100]{};
	char patternReflectedR270[100]{};
	char patternReflected[100]{};

	char patternCompare[100]{};

	fin >> pSize;
	for (int i = 0; i < pSize * pSize; i++)
	{
		fin >> pattern[i];
	}

	for (int i = 0; i < pSize * pSize; i++)
	{
		fin >> patternCompare[i];
	}

	reflect(pattern, patternReflected, pSize);
	rotate90(pattern, patternRotated90, pSize);
	rotate90(patternReflected, patternReflectedR90, pSize);
	rotate90(patternRotated90, patternRotated180, pSize);
	rotate90(patternReflectedR90, patternReflectedR180, pSize);
	rotate90(patternRotated180, patternRotated270, pSize);
	rotate90(patternReflectedR180, patternReflectedR270, pSize);

	if (comparePatterns(patternCompare, patternRotated90, pSize)) fout << 1 << endl;
	else if (comparePatterns(patternCompare, patternRotated180, pSize)) fout << 2 << endl;
	else if (comparePatterns(patternCompare, patternRotated180, pSize)) fout << 2 << endl;
	else if (comparePatterns(patternCompare, patternRotated270, pSize)) fout << 3 << endl;
	else if (comparePatterns(patternCompare, patternReflected, pSize)) fout << 4 << endl;
	else if (comparePatterns(patternCompare, patternReflectedR90, pSize)
		|| comparePatterns(patternCompare, patternReflectedR180, pSize)
		|| comparePatterns(patternCompare, patternReflectedR270, pSize))
		fout << 5 << endl;
	else if (comparePatterns(patternCompare, pattern, pSize)) fout << 6 << endl;
	else fout << 7 << endl;

	return 0;
}
