#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

// new approach: order k 'increase speed' times, maxSpeed-k 'decrease speed' times,
// and n 'do nothing' times and see if it's possible to get the distance

int maxDistance(int time, int maxSpeed)
{// k increase speed, k-maxspeed decrease speed, 2k-maxspeed = time
	// if Bessie can keep increasing speed
	if (time <= maxSpeed)
		return time * (time + 1) / 2;
	else
	{
		int numIncreases = (time + maxSpeed) / 2;
		int numDecreases = numIncreases - maxSpeed;
		return numIncreases * (numIncreases + 1) / 2 + numIncreases * (time - numIncreases)
			- numDecreases * (numDecreases + 1) / 2;
	}
}

int main()
{
#ifndef TESTING
	ofstream fout("race.out");
	ifstream fin("race.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	// map time to max distance with max speed restraint

	int raceLength;
	int numTests;

	//for (int i = 1; i < 10; i++)
	//	fout << maxDistance(5, i) << ' ';

	fin >> raceLength >> numTests;

	for (int i = 0; i < numTests; i++)
	{
		int maxSpeed;
		fin >> maxSpeed;
		int counter = 1;
		while (true)
		{
			if (maxDistance(counter, maxSpeed) >= raceLength)
			{
				fout << counter << endl;
				break;
			}
			counter++;
		}
	}


	//for (int i = 0; i < numTests; i++)
	//{
	//	bool needToPrint = true;
	//	int maxSpeedAtEnd;
	//	fin >> maxSpeedAtEnd;
	//	int minTime = 1000000001;
	//	// if Bessie can keep on increasing speed, let them do that
	//	int closeSquareRoot = int(sqrt(2 * raceLength) + 0.000001);
	//	if (raceLength > closeSquareRoot * (closeSquareRoot - 1) / 2
	//		&& raceLength <= closeSquareRoot * (closeSquareRoot + 1) / 2
	//		&& closeSquareRoot <= maxSpeedAtEnd)
	//	{
	//		minTime = closeSquareRoot;
	//		needToPrint = false;
	//	}
	//	else if (raceLength > closeSquareRoot * (closeSquareRoot + 1) / 2
	//		&& raceLength <= (closeSquareRoot + 1) * (closeSquareRoot + 2) / 2
	//		&& closeSquareRoot <= maxSpeedAtEnd)
	//	{
	//		minTime = closeSquareRoot + 1;
	//		needToPrint = false;
	//	}

	//	// if Bessie can't keep on increasing speed and must lower it, then do this
	//	for (int i = 0; i < maxSpeedAtEnd; i++) // Bessie can finish up to maxSpeed-1 in front of finish
	//	{
	//		int newLength = raceLength + maxSpeedAtEnd * (maxSpeedAtEnd - 1) + i;
	//		int extraTime = maxSpeedAtEnd - 1;
	//		int aboveSquareRoot = int(sqrt(newLength) - 0.000001) + 1;
	//		if (newLength > (aboveSquareRoot) * (aboveSquareRoot - 1) && needToPrint)
	//		{
	//			int placeholder = aboveSquareRoot * 2 - 1 - extraTime;
	//			if (placeholder < minTime) minTime = placeholder;
	//		}
	//		else if (needToPrint)
	//		{
	//			int placeholder = aboveSquareRoot * 2 - 2 - extraTime;
	//			if (placeholder < minTime) minTime = placeholder;
	//		}
	//	}
	//	fout << minTime << endl;
	//}


	/*for (int i = 1; i <= 30; i++)
	{
		int raceLength = i;
		bool needToPrint = true;
		int maxSpeedAtEnd = 1;
		int minTime;
		// if Bessie can keep on increasing speed, let them do that
		int closeSquareRoot = int(sqrt(2 * raceLength) + 0.000001);
		if (raceLength > closeSquareRoot * (closeSquareRoot - 1) / 2
			&& raceLength <= closeSquareRoot * (closeSquareRoot + 1) / 2
			&& closeSquareRoot <= maxSpeedAtEnd)
		{
			minTime = closeSquareRoot;
			needToPrint = false;
		}
		else if (raceLength > closeSquareRoot * (closeSquareRoot + 1) / 2
			&& raceLength <= (closeSquareRoot + 1) * (closeSquareRoot + 2) / 2
			&& closeSquareRoot <= maxSpeedAtEnd)
		{
			minTime = closeSquareRoot + 1;
			needToPrint = false;
		}

		// if Bessie can't keep on increasing speed and must lower it, then do this
		int newLength = raceLength + maxSpeedAtEnd * (maxSpeedAtEnd - 1);
		int extraTime = maxSpeedAtEnd - 1;
		int aboveSquareRoot = int(sqrt(newLength) - 0.000001) + 1;
		if (newLength > (aboveSquareRoot) * (aboveSquareRoot - 1) && needToPrint)
			minTime = aboveSquareRoot * 2 - 1 - extraTime;
		else if (needToPrint)
			minTime = aboveSquareRoot * 2 - 2 - extraTime;
		fout << minTime << endl;
	}*/

	return 0;
}