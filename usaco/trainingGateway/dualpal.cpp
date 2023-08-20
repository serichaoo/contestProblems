/*
ID: sericha1
TASK: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

char map[10];

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

bool isDualPal(int number)
{
	int palCount = 0;
	for (int base = 2; base <= 10; base++)
	{
		if (isPalindrome(base10ToBaseB(number, base))) palCount++;
	}
	return palCount >= 2;
}

int main()
{
	ofstream fout("dualpal.out");
	ifstream fin("dualpal.in");
	//ostream& fout = cout;
	//istream& fin = cin;

	int numberToSearch;
	fin >> numberToSearch;
	int start;
	fin >> start;

	for (int i = 0; i < 10; i++) map[i] = '0' + i;

	int foundDualPals = 0;
	int counter = 1;
	while (foundDualPals < numberToSearch)
	{
		if (isDualPal(start + counter))
		{
			fout << (start + counter) << endl;
			foundDualPals++;
		}
		counter++;
	}

	return 0;
}

