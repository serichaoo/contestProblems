/*
ID: sericha1
TASK: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

char map[20];

string base10ToBaseB(int number, int base)
{
	string result{};
	int currentNumber{ number };
	while (currentNumber > 0)
	{
		result.push_back(map[currentNumber % base]);
		//result = map[currentNumber % base] + result;
		currentNumber /= base;
	}
	reverse(result.begin(), result.end());
	return result;
}

bool isPalindrome(string number)
{
	for (int i = 0; i < number.length() / 2 + 1; i++)
		if (number[i] != number[number.length() - 1 - i]) return false;
	return true;
}

int main()
{
	//ofstream fout("palsquare.out");
	//ifstream fin("palsquare.in");
	ostream& fout = cout;
	istream& fin = cin;

	int base;
	fin >> base;

	for (int i = 0; i < 10; i++) map[i] = '0' + i;
	for (int i = 0; i < 10; i++) map[i + 10] = 'A' + i;

	for (int i = 1; i <= 300; i++)
	{
		if (isPalindrome(base10ToBaseB(i * i, base)))
			fout << base10ToBaseB(i, base) << ' ' << base10ToBaseB(i * i, base) << endl;
	}

	return 0;
}


