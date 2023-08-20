/*
ID: sericha1
TASK: pprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// generate all palindromes in range, then check if each is prime
vector<int> validInts;

int intPow(int base, int exp)
{
	if (exp == 0) return 1;
	return base * pow(base, exp - 1);
}

int stringToInt(string x)
{
	int total = 0;
	for (int i = 0; i < x.length(); i++)
	{
		total += (x[i] - '0') * intPow(10, x.length() - i - 1);
	}
	return total;
}

string flipString(const string& x)
{
	char newString[6];
	for (int i = 0; i < x.length(); i++)
		newString[i] = x[x.length() - 1 - i];
	newString[x.length()] = '\0';
	return newString;
}

bool isPrime(int x)
{
	for (int i = 2; i < pow(x, 0.5) + 0.001; i++)
		if (x % i == 0) return false;
	return true;
}


int main()
{
#ifndef TESTING
	ofstream fout("pprime.out");
	ifstream fin("pprime.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	//cout << flipString("1234");
	//cout << isPrime(19);
	int minimum, maximum;
	fin >> minimum >> maximum;

	for (int i = 1; i <= 9999; i++)
	{
		int x = stringToInt(to_string(i) + flipString(to_string(i)));
		if (x >= minimum && x <= maximum && isPrime(x)) validInts.push_back(x);
		int y = stringToInt((to_string(i).substr(0, to_string(i).length() - 1)) + flipString(to_string(i)));
		if (y >= minimum && y <= maximum && isPrime(y)) validInts.push_back(y);
	}

	sort(validInts.begin(), validInts.end());

	for (int i = 0; i < validInts.size(); i++)
		fout << validInts[i] << endl;

	return 0;
}
