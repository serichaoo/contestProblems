/*
ID: sericha1
TASK: sprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> validSprimes;

bool isPrime(int x)
{
	for (int i = 2; i < pow(x, 0.5) + 0.001; i++)
		if (x % i == 0) return false;
	return true;
}

int intPow(int pow, int exp)
{
	if (exp == 0) return 0;
	return intPow(pow, exp - 1);
}

int numDigits(int x)
{
	return int(log(x) / log(10)) + 1;
}

/*int stringToInt(string x)
{
	int total = 0;
	for (int i = 0; i < x.length(); i++)
		total += x[i] * intPow(10, x.length() - 1 - i);
	return total;
}*/

// solve by recursing upwards from 1 to N by adding an odd integer at the end

void generateSprimes(int currentSprime, int length) // only works if original number is prime
{
	if (numDigits(currentSprime) == length)
		validSprimes.push_back(currentSprime);
	else
		for (int i = 0; i < 5; i++)
		{
			if (isPrime(currentSprime * 10 + 2 * i + 1))
				generateSprimes(currentSprime * 10 + 2 * i + 1, length);
		}
}

int main()
{
#ifndef TESTING
	ofstream fout("sprime.out");
	ifstream fin("sprime.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	int length;
	fin >> length;

	int firstPrimes[4]{ 2, 3, 5, 7 };

	for (int i = 0; i < 4; i++)
		generateSprimes(firstPrimes[i], length);

	sort(validSprimes.begin(), validSprimes.end());

	for (int i = 0; i < validSprimes.size(); i++)
		fout << validSprimes[i] << endl;

	return 0;
}
