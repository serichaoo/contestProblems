/*
ID: sericha1
TASK: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct milkSchedule
{
	int time;
	bool isStart;
};

/*
bool isStart(milkSchedule* list, int numberOfFarmers, int time)
{
	for (int i = 0; i < 2 * numberOfFarmers; i++)
	{
		if (list[i].time == time) return list[i].isStart;
	}
	throw(false);
}
*/

bool compareTimes(milkSchedule a, milkSchedule b)
{
	return (a.time < b.time || (a.time == b.time && a.isStart && !b.isStart)); // return (a.time < b.time);
}

int main()
{
	ofstream fout("milk2.out");
	ifstream fin("milk2.in");
	//ostream& fout = cout;
	//istream& fin = cin;

	milkSchedule schedule[10000];

	int timeDifferences[9999];

	int numberOfFarmers;
	fin >> numberOfFarmers;

	for (int i = 0; i < 2 * numberOfFarmers; i += 2)
	{
		fin >> schedule[i].time;
		schedule[i].isStart = true;
		fin >> schedule[i + 1].time;
		schedule[i + 1].isStart = false;
	}

	/*
	for (int i = 0; i < 2 * numberOfFarmers; i++)
	{
		scheduleTimes[i] = schedule[i].time;
	}
	sort(scheduleTimes, scheduleTimes + 2 * numberOfFarmers);
	*/

	sort(schedule, schedule + 2 * numberOfFarmers, compareTimes);

	for (int i = 0; i < 2 * numberOfFarmers - 1; i++)
	{
		timeDifferences[i] = schedule[i + 1].time - schedule[i].time;
	}

	int maximumMilkTime{ 0 };
	int maximumNonMilkTime{ 0 };
	int tempMax{ 0 };
	int counter{ 0 };

	for (int i = 0; i < 2 * numberOfFarmers - 1; i++)
	{
		if (schedule[i].isStart == true) counter++;
		else counter--;
		if (counter == 0) // if (counter == 0 && timeDifferences[i] != 0)
		{
			tempMax = 0;
			if (timeDifferences[i] > maximumNonMilkTime) maximumNonMilkTime = timeDifferences[i];
		}
		else
		{
			tempMax += timeDifferences[i];
			if (tempMax > maximumMilkTime) maximumMilkTime = tempMax;
		}
	}

	fout << maximumMilkTime << ' ' << maximumNonMilkTime << endl;

	return 0;
}

