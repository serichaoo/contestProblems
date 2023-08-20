/*
ID: sericha1
TASK: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>


//Saturday will be day 1, Sunday day 2, ..., Friday day 6
//The first day is a Monday

using namespace std;

int numberOfEachDay[7]{ 0 };
int daysInEachMonthRegularYear[]{ 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
int daysInEachMonthLeapYear[]{ 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};

void year(int& currentDay, bool leapYear)
{
	int* daysInEachMonth = daysInEachMonthRegularYear;
	if (leapYear) daysInEachMonth = daysInEachMonthLeapYear;

	for (int i = 0; i < 12; i++)
	{
		numberOfEachDay[(currentDay + 12) % 7]++;
		currentDay += daysInEachMonth[i];
		currentDay %= 7;
	}
}

int main()
{
	//ofstream fout("friday.out");
	//ifstream fin("friday.in");

	int startingDay{ 2 };
	int numberOfYears{};
	cin >> numberOfYears;
	for (int i = 0; i < numberOfYears; i++)
	{
		bool leapYear;
		if ((1900 + i) % 400 == 0)
			leapYear = true;
		else
			if ((1900 + i) % 100 == 0)
				leapYear = false;
			else
				if ((1900 + i) % 4 == 0)
					leapYear = true;
				else
					leapYear = false;
		year(startingDay, leapYear);
	}
	for (int i = 0; i < 6; i++)
		cout << numberOfEachDay[i] << ' ';
	cout << numberOfEachDay[6] << endl;
	return 0;
}